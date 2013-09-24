#include<cstdio>
#include<cstdlib>
using namespace std;

int search(long long int* arr,int len,long long int value)
{
//	printf("Searching for %lld\n",value);
	int left = 0;
	int right = len-1;
	int middle;
	while(left!=right)
	{
		middle = (left+right)/2;

		if(arr[middle]>=value)
			right = middle;
		else left = middle+1;
	}
//	printf("Returning index %d and value %lld\n",left,arr[left]);
	return left;
}

void display(long long int* arr,int len)
{
	for(int i=0;i<len;i++)
		{
			printf("%lld\t",arr[i]);
		}
	printf("\n");
}
int main()
{
	int n,i,j;
	int index;
	scanf("%d",&n);

	long long int arr[n-1];
	long long int arrcpy[n-1];
	scanf("%lld",&arr[0]);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld",&arr[i]);
		arr[i]--;
		arrcpy[i]=arr[i];
	}
	
	for (i=0;i<n-1;i++)
	{
		if(arr[i]!=0)
		{
			
			j = 2;
	
			while(1)
			{
				index = search(arr,n-1,arr[i]*j);
				if(arr[index]!=(arr[i]*j))
				{
					break;
				}
				else 
				{
					arrcpy[index]=0;
					j++;
				}
			}
		}	
	}
	int count = 0;
	for (i=0;i<n-1;i++)
	{
		if(arrcpy[i]!=0)
			count++;
	}
	//display(arrcpy,n-1);
	//display(arr,n-1);
	if(count>0)
		printf("%d\n",count);
	else printf("1\n");
	
	return 0;
}
