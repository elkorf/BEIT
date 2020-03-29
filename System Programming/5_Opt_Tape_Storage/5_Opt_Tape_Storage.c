#include<stdlib.h> 
#include<stdio.h> 

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	i = 0;
	j = 0; 
	k = l;
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; 

		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 

void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int num_jobs, num_tapes;
	printf("\nEnter number of jobs:");
	scanf("%d",&num_jobs);

	printf("\nEnter number of tapes:");
	scanf("%d",&num_tapes);

	int jobs[num_jobs+1], tapes[num_tapes+1][num_jobs+1], unstored[num_jobs], sum[num_tapes][1];

	printf("\nEnter jobs:");
	for(int i=0;i<num_jobs;i++)
		scanf("%d",&jobs[i]);
	

	for(int i=0;i<num_tapes;i++)
	{
		for(int j=1;j<num_jobs;j++)
			tapes[i][j] = 0;
	}
	
	printf("\nEnter size of each tape:");
	for(int i=0;i<num_tapes;i++)
	{
		printf("\nTAPE [%d] :",i+1);
		scanf("%d",&tapes[i][0]);
		sum[i][0] = tapes[i][0];
	}


	mergeSort(jobs, 0, num_jobs - 1); 
	
	printf("\nSorted array:");
	printArray(jobs, num_jobs);
	
	
	int k = 0, l = 1, temp, num = 0, flg = 0, count = 0, flag = 0, counter = 0;
	for(int j=0;j<num_jobs;j++)
	{
		for(int i=count;i<num_tapes;i++)
		{
			temp = tapes[i][0] - jobs[j];
			if(temp >= 0)
			{
				tapes[i][0] = temp;
				tapes[i][l] = jobs[j];
				count++;
				if(count % num_tapes == 0)
				{	
					l++;
					count = 0;
				}
				flg = 1;
			}
			if(flg)
			{
				flg = 0;
				break;
			}
			if((count+1) % num_tapes == 0 && temp < 0)
			{
				i = -1;
				l++;
				count = 0;
			}
		}
	}
	int j,i;
	for(i=0;i<num_tapes;i++)
	{
		printf("TAPE [%d] :",i+1);
		int temp = 0, res = 0, counter = 0;
		for(j=0;j<num_jobs;j++)
		{
			if(tapes[i][j] != 0)
			{	
				printf("%d\t",tapes[i][j]);
				counter++;
			}
		}
		sum[i][0] = (counter-1);
		printf("\n");
	}
	double MRT = 0;
	for(int k =0;k<num_tapes;k++)
	{
		MRT = 0, temp = 0;
		for(i=0;i<sum[k][0];i++)
		{	
			temp = 0;
			for(j=0;j<=i;j++)
			{
				temp += tapes[k][j+1];
				//printf("TEMP = %d\n",temp);
			}
			MRT += temp;	
		}
		printf("MRT for TAPE [%d] = %f\n",(k+1), (MRT/sum[k][0]));
	}
	if(flag)
	{
		printf("\nNot ordered job:");
		for(k=0;k<num;k++)
			printf("%d\t",unstored[k]);
	}	
	
	/*for(int k=0;k<i;k++)
		printf("MEAN OF TAPE [%d] = %d\n",k+1,sum[k][0]);*/
	return 0; 
}
