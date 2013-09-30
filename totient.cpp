#include<cstdio>
#include<cstdlib>
#include<list>
#include<cmath>
using namespace std;

int primefactors[100001][7];
int len[100001];
bool isprime[100001];

void build_primefactors()
{
	fill(len,len+100001,0);
	fill(isprime,isprime+100001,true);
	for(int i=2;i<100001;i++)
	{
		if(isprime[i])
		{
			for(int k=i;k<100001;k+=i)
			{
				primefactors[k][len[k]] = i;
				isprime[k]=false; 
				len[k]++;
			}
		}
	}

}


int totient(int n)
{
		int m=n;
		int sum=m;
		int x = 1<<len[n];
		for(int k=1;k<x;k++)
		{
			int kcopy=k;
			int count=0;
			int temp=0;
			int product=1;
			while(k>0)
			{
				if(k%2==1)
				{
					product = product*primefactors[n][count];
					temp++;
				}
				count++;
				k=k/2;
			}

			if(temp%2==0)
				sum += (m/product);
			else sum -= (m/product);	
			k=kcopy;
		}
		return sum;
	
}


int main()
{
	int t,n;
	scanf("%d",&t);
	build_primefactors();
		
	long long int sum=0;
	int totient_sum[100001];
	for(int i=1;i<=100000;i++)
	{
		
		totient_sum[i]=totient(i);
	}

	while(t--)
	{
		scanf("%d",&n);
		int ans = 0;
	
		printf("%lld\n",totient_sum[n]);	
	}
	return 0;
}
