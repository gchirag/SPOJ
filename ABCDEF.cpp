#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);

	int arr[n];
	
	int count0 = 0;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
		if(arr[i]==0)
			count0++;
	}
	
	int** arr2 = (int**) malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
	{
		arr2[i] = (int*)malloc(sizeof(int) * n);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr2[i][j] = arr[i]*arr[j];
		}
	}
	
	int* arr3 = (int*) malloc(sizeof(int) * (n-count0)*n*n);

	int len = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					arr3[len++] = arr2[i][j]+arr2[i][k];
				}
			}
		}
	}
	sort(arr3,arr3+(n-count0)*n*n);
	
//	for(int i=0;i<(n-count0)*n*n;i++)
//	{
//		printf("%d\t",arr3[i]);
//	}
//	printf("\n");



	int* arr4 = (int*)malloc(sizeof(int)*n*n*n);
	len=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				arr4[len++]=arr2[i][j]+arr[k];
			}
		}
	}
	
	sort(arr4,arr4+n*n*n);
//	for(int i=0;i<n*n*n;i++)
//	{
//		printf("%d\t",arr4[i]);
//	}
//	printf("\n");
		
	free(arr2);
	
	int array1index = 0;
	int array2index = 0;
	int count1=0,count2=0,val;
	int sum=0;
	
	while(array1index<n*n*n && array2index<(n-count0)*n*n)
	{
		//prevarray1 =  arr4[array1index];
		if(arr4[array1index]<arr3[array2index])
		{
			array1index++;
		}
		else if(arr4[array1index]>arr3[array2index])
		{
			array2index++;
		}
		else
		{
			//printf("index2 %d index1 %d\n",array2index,array1index);
			val = arr4[array1index];
			count1 = 1;
			count2 = 1;
			array1index++;array2index++;
			
			while(array2index<(n-count0)*n*n && arr3[array2index]==val)
			{
				count1++;
				array2index++;
			}
			while(array1index<n*n*n && arr4[array1index]==val)
			{
				count2++;
				array1index++;
			}
			
			//printf("Count1 %d Count2 %d\n",count1,count2);		
			//prevcount = count;
			sum += count1*count2;
			
		}

	}

	printf("%d\n",sum);
	free(arr3);
	free(arr4);
	return 0;
}
