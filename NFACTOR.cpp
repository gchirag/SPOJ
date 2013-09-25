#include<cstdio>
#include<cstdlib>
#include<list>
#include<cmath>
using namespace std;

int primes[100000];
bool isprime[1000001];
int len;
int count[1000001];
int ans[1000000][11];
int helper[11];

void display(int* arr,int len)
{
	for(int i =0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void build_primes()
{
	fill(isprime,isprime+1000001,true);
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<=1000;i++)
	{
		for(int j=i*i;j<1000001;j+=i)
		{
			isprime[j]=false;
		}
	}
	len=0;
	for(int i=0;i<1000000;i++)
	{
		if(isprime[i])
		{
			primes[len++]=i;
		}
	}
}

void nfactor(int* count,int a, int b)
{
	
	for(int i=0;i<len && primes[i]<=b;i++)
	{
		for(int temp = primes[i];temp<=b;temp+=primes[i])
		{
			//printf("incrementing value %d for prime %d\n",temp,primes[i]);
			count[temp-a]++;
		}
	}	
//display(count,13);
	helper[0]=1;
	for(int i=a+2;i<=b;i++)
	{
		helper[count[i]]++;
		
		for(int j=0;j<11;j++)
		{
			ans[i][j]=helper[j];
		}
	}
//display(ans[1],11);	
//display(ans[10],11);	
	
}


int main()
{
	int t,a,b,n;
	scanf("%d",&t);
	
	build_primes();
	
	for(int i=0;i<1000000;i++)
	{
		count[i]=0;
	}

	nfactor(count,0,1000000);

	while(t--)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&n);

		printf("%d\n",ans[b][n]-ans[a-1][n]);
	
	}
	return 0;
}
