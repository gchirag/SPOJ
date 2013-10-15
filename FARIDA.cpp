#include<cstdio>
#include<cstdlib>
using namespace std;
#define max(a,b) (a>b)? a:b

int arr[10001];
long long int dp[10001];

int main()
{
	int t,n;
	scanf("%d",&t);
	int tcopy=t;
	
	while(t--)
	{
		scanf("%d",&n);
//		int* arr = (int*) malloc (sizeof(int)*n);
//		long long int* dp = (long long int*) malloc (sizeof(long long int)*n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		dp[0]=arr[0];
		dp[1]=max(arr[0],arr[1]);
		
		for(int i=2;i<n;i++)
		{
			dp[i] = max(dp[i-2]+arr[i],dp[i-1]);
		}
		
		printf("Case %d: %lld\n",tcopy-t,dp[n-1]);
		
//		free(arr);
//		free(dp);
	}
	return 0;
}
