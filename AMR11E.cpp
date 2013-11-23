#include<cstdio>
#include<cstdlib>
#include<list>
using namespace std;

int ans[1001];
int primes[1000];
int len;
bool isprime[30000];
//int len2;

void build_primes()
{
	fill(isprime,isprime+30000,true);
	for(int i=2;i<1800;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<30000;j+=i)
			{
				isprime[j]=false;
			}
		}
	}
	len=0;
	for(int i=2;i<30000;i++)
	{
		if(isprime[i])
			primes[len++]=i;
	}
}

void build_ans()
{
	build_primes();
	int count[30000];
	fill(count,count+30000,0);
	
	for(int i=0;i<len;i++)
	{
		for(int j=primes[i];j<30000;j+=primes[i])
		{
			count[j]++;
		}
	}
	
	int helperlen=1;
	
	for(int i=25;i<30000;i++)
	{
		if(helperlen==1001)
			break;
			
		if(count[i]>=3)
			ans[helperlen++]=i;

	}	
	
}
int main()
{
	build_ans();
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}
