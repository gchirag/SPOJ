#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int primes[200];
bool isprime[1001];
int len;
int count1[168];
int count2[168];

void build_primes()
{
	for(int i=2;i<1001;i++)
	{
		isprime[i]=true;
	}

	for(int i=2;i<1001;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<1001;j+=i)
			{
				isprime[j]=false;
			}
		}
	}
	len=0;
	for(int i=2;i<1001;i++)
	{
		if(isprime[i])
			primes[len++]=i;
	}
}
int main()
{
	build_primes();
	int a,b,acopy,bcopy,dimension,distance;
	scanf("%d%d",&a,&b);
	int t=1;
	while(a!=0 && b!=0)
	{
		for(int i=0;i<168;i++)
		{
			count1[i]=0;
			count2[i]=0;
		}	

		dimension = 0;
		distance = 0;
		acopy=a;
		bcopy=b;
		for(int i=0;i<len && primes[i]<=a;i++)
		{
			while(a%primes[i]==0)
			{
				count1[i]++;
				a = a/primes[i];
			}
			//printf("After removing %d a becomes %d\n",primes[i],a);
		}
		for(int i=0;i<len && primes[i]<=b;i++)
		{
			while(b%primes[i]==0)
			{
				count2[i]++;
				b = b/primes[i];
			}
		}

		for(int i=0;i<len;i++)
		{
			if(count1[i]||count2[i])
				dimension++;
			distance+=abs(count1[i]-count2[i]);
		}
		if(a!=1 && b!=1)
		{
			dimension++;
			if(a!=b)
			{
				dimension++;
				distance+=2;
			}
		}
		if((a!=1 && b==1)||(a==1 && b!=1))
		{
			dimension++;distance++;
		}
		
		printf("%d. %d:%d\n",t,dimension,distance);
		scanf("%d%d",&a,&b);
		t++;
	}
}
