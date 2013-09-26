#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	long long int t,n,tcopy;
	long long int sum,minsum;
	
	scanf("%lld",&t);
	tcopy=t;
	while(t--)
	{
		scanf("%lld",&n);
		int x;
		sum=0;
		minsum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			sum=sum+x;
			if(sum<minsum)
				minsum=sum;
		}
		printf("Scenario #%lld: %lld\n",tcopy-t,abs(minsum)+1);	
		
	}
	return 0;
}
