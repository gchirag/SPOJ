#include<cstdio>
#include<cstdlib>
#include<list>
#include<cmath>
using namespace std;

int prime[100000];
bool isprime[1000000];
int len;

void build_primes()
{
	fill(isprime,isprime+1000000,true);

	isprime[0]=false;
	isprime[1]=false;

	for(int i=2;i<=sqrt(1000000);i++)
	{
		for(int j=i*i;j<=1000000;j+=i)
		{
			isprime[j]=false;
		}
	}
	
	len=0;
	for(int i=0;i<1000000;i++)
	{
		if(isprime[i])
		    prime[len++]=i;
	}
}

bool primeornot(long long int x)
{
	if(x<1000000)
	    return isprime[x];
	else
	{
		for(int i=0;prime[i]<=sqrt(x);i++)
		{
			if(x%prime[i]==0)
			    return false;
		}
		return true;
	}
}


int main()
{
	int t;
	long long int a,b;
	scanf("%d",&t);
	
	build_primes();
	while(t--)
	{
		scanf("%lld",&a);
		scanf("%lld",&b);
		
		for(long long int i=a;i<=b;i++)
		{
			if(primeornot(i))
			    printf("%lld\n",i);
		}
		printf("\n");
	}
	return 0;
	//system("PAUSE");
}
