#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct sum_struct
{
	long long int sum;
	int index;
};

bool comparer(sum_struct s1,sum_struct s2)
{
	return s1.sum<s2.sum;
}
int main()
{
	int n,t;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		long long int* a = (long long int*) malloc(sizeof(long long int)*n);
		sum_struct* sum = (sum_struct*) malloc(sizeof(sum_struct)*(n+1));
		long long int summer=0;
		
		sum[0].sum=0;
		sum[0].index=-1;
		
		for(int i=0;i<n;i++)
		{
			scanf("%lld",a+i);
			summer+=a[i];
			sum[i+1].sum = summer;
			sum[i+1].index = i;
		}

		sort(sum,sum+n,comparer);

		int left = 0;
		int right = 1;
		int count = 0;
		int samelength = 0;
		for(;right<=n;)
		{
			if(sum[right].sum-sum[left].sum==47)
			{
				while(sum[right].sum-sum[left].sum==47 && right<=n)
				{
					if(sum[right].index>sum[left].index)
					{
						count++;
					}
					right++;
					samelength++;						//samelength++;
				}
					
				left++;
				right = right-samelength;
				samelength = 0;
			}
			
			else if(sum[right].sum-sum[left].sum<47)
			{
				right++;
			}
			else left++;
		}
		printf("%d\n",count);

		free(a);
		free(sum);

	}
	return 0;
}
