#include<cstdio>
#include<cstdlib>
using namespace std;

void display(int **arr,int n,int k)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
	
}
int main()
{
	int n,k,a,b;
	scanf("%d%d",&n,&k);
	
	while(!(n==-1 && k==-1))
	{
		scanf("%d%d",&a,&b);
		
		//printf("%d---%d\n",a,b);
		b=(b+n-a)%n;
		a=0;
		//printf("%d---%d\n",a,b);
		k=k+1;
		long long int dp[n][k];
		
		for(int i=1;i<n;i++)
		{
			dp[i][0]=0;
		}
		dp[0][0]=1;
		
		for(int i=1;i<k;i++)
		{
			for(int j=0;j<n;j++)
			{
				//printf("==> i---%d---- j----%d----- j-1 mod n----%d---- j+1 mod n----%d\n",i,j,(n+j-1)%n,(j+1)%n);
				dp[j][i]=dp[(n+j-1)%n][i-1]+dp[(j+1)%n][i-1];
			}
		}
		
		
		
		
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<k;j++)
//		{
//			printf("%d\t",dp[i][j]);
//		}
//		printf("\n");
//	}
	
		
		printf("%lld\n",dp[b][k-1]);
		
		
		
		scanf("%d%d",&n,&k);
	}
}
