
package LogFile;

import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import org.apache.hadoop.conf.Configuration;

import org.apache.hadoop.fs.Path;

import org.apache.hadoop.io.IntWritable;

import org.apache.hadoop.io.LongWritable;

import org.apache.hadoop.io.Text;

import org.apache.hadoop.mapreduce.Job;

import org.apache.hadoop.mapreduce.Mapper;

import org.apache.hadoop.mapreduce.Reducer;

import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;

import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import org.apache.hadoop.util.GenericOptionsParser;

public class LogFile {

	public static void main(String [] args) throws Exception
	
	{
		
		Configuration c=new Configuration();
		
		String[] files=new GenericOptionsParser(c,args).getRemainingArgs();
		
		Path input=new Path(files[0]);
		
		Path output=new Path(files[1]);
		
		Job j=new Job(c,"log");
		
		j.setJarByClass(LogFile.class);
		
		j.setMapperClass(MapForLog.class);
		
		j.setReducerClass(ReduceForLog.class);
		
		j.setOutputKeyClass(Text.class);
		
		j.setOutputValueClass(IntWritable.class);
		
		FileInputFormat.addInputPath(j, input);
		
		FileOutputFormat.setOutputPath(j, output);
		
		System.exit(j.waitForCompletion(true)?0:1);
	
	}
	
	public static class MapForLog extends Mapper<LongWritable, Text, Text, IntWritable>{
	
		public void map(LongWritable key, Text value, Context con) throws IOException, InterruptedException{	
			String line = value.toString();
			String[] words=line.split(",");
			Text outputKey = null;
			long diff;
			IntWritable outputValue;
			DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
			LocalDateTime time1, time2 = null;
			
			for(int i=0;i<words.length;i=i+8)
			{
				outputKey = new Text(words[i+1].trim());
				time1 = LocalDateTime.parse(words[i+5],formatter);
				time2 = LocalDateTime.parse(words[i+7],formatter);
				diff = java.time.Duration.between(time1,time2).toMinutes();
				outputValue = new IntWritable((int)diff);
				con.write(outputKey, outputValue);
			}
		}
	}
	
	public static class ReduceForLog extends Reducer<Text, IntWritable, Text, IntWritable>{
		int max_sum = 0;
		Text max_logtime = new Text();
		public void reduce(Text word, Iterable<IntWritable> values, Context con) throws IOException, InterruptedException{
		
			int sum = 0;
		
		   for(IntWritable value : values)
		   {
			   	sum += value.get();
		   }
		   con.write(word, new IntWritable(sum));
		   
		   if(sum > max_sum)
		   {
			   max_sum = sum;
			   max_logtime.set("\nMaximum time logged In User (In Minutes) : "+word);
		   }
		}
		
		protected void cleanup(Context con) throws IOException, InterruptedException{
			con.write(max_logtime, new IntWritable(max_sum));
			
		}
	}
}	
