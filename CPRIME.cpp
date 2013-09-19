#include<cstdio>
#include<cstdlib>
#include<list>
#include<cmath>
using namespace std;

int prime[6000000];
bool isprime[50000000];
int len;

void build_primes()
{
	fill(isprime,isprime+,true);

	isprime[0]=false;
	isprime[1]=true;

	for(int i=3;i<=sqrt(100000000);i+=2)
	{
		if(isprime[i/2])
			for(int j=i*i;j<=100000000;j+=2*i)
			{
				isprime[j/2]=false;
			}
	}

	len=0;
	prime[len++]=2;
	
	for(int i=0;i<50000000;i++)
	{
		if(isprime[i])
			prime[len++]=i*2+1;
	}
	
}

int search(int a)
{
	int left=0;
	int right=len-1;

	while(left!=right)
	{
		int middle = (left+right)/2;
		if(prime[middle]>a)
		    right=middle;
		else left=middle+1;
	}
	return left;
}

int main()
{
	int t;
	int n;
	double x,pct;
	scanf("%d",&t);

	build_primes();
	while(t!=0)
	{
		n = search(t);
		x = t/(double)log(t);
		
		pct = abs(n-x)/(double)n*100;
		printf("%0.1lf\n",round(pct*10)/10);

		scanf("%d",&t);
	}
	return 0;
}
