import java.io.IOException;

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

public class Wheather {

	public static void main(String [] args) throws Exception{
		Configuration c=new Configuration();
		
		Path input=new Path(args[0]);
		
		Path output=new Path(args[1]);
		
		Job j=new Job(c,"wordcount");
		
		j.setJarByClass(Wheather.class);
		
		j.setMapperClass(MapForWordCount.class);
		
		j.setReducerClass(ReduceForWordCount.class);
		
		j.setOutputKeyClass(Text.class);
		
		j.setOutputValueClass(IntWritable.class);
		
		FileInputFormat.addInputPath(j, input);
		
		FileOutputFormat.setOutputPath(j, output);
		
		System.exit(j.waitForCompletion(true)?0:1);
	
	}

	public static class MapForWordCount extends Mapper<LongWritable, Text, Text, IntWritable>{
		
		public void map(LongWritable key, Text value, Context con) throws IOException, InterruptedException
		{
			String line = value.toString();
			int temp = 0;
			String temperature = line.substring(87,92);
			String year = line.substring(15,19);
			temp = Integer.parseInt(temperature);
			Text outputKey = new Text(year);
			
			IntWritable outputValue = new IntWritable(temp);
			
			con.write(outputKey, outputValue);	
		}
	}
	public static class ReduceForWordCount extends Reducer<Text, IntWritable, Text, IntWritable>{
		
		Text maxWord = new Text();
		Text minWord = new Text();
		int min = 9999;
		int max = 0;
	
		public void reduce(Text word, Iterable<IntWritable> values, Context con) throws IOException, InterruptedException{
			int sum = 0;
			int count = 0;
			for(IntWritable value : values)	
			{	
				sum += value.get();
				count++;
			}
			int avg = sum / count;
			if(max<=avg) {
				max = avg;
				maxWord.set(word);
			}
			if(min >= avg) {
				min = avg;
				minWord.set(word); 
			}	  
		}

	@Override
		protected void cleanup(Reducer<Text, IntWritable, Text, IntWritable>.Context context)
				throws IOException, InterruptedException {
			// TODO Auto-generated method stub
		   context.write(maxWord, new IntWritable(max));
		   context.write(minWord, new IntWritable(min));
		
		super.cleanup(context);
		}	
	}
}