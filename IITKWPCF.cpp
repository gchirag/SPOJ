#include<cstdio>
#include<cstdlib>
#include<list>
#include<cmath>
using namespace std;

int prime[100000];
int len;
bool primeornot[1000000];


bool isprime(long long int n)
{
	if(n<=1000000)
	    return primeornot[n];
	else
	{
		for(int i=0;prime[i]<=sqrt(n);i++)
		{
			if(n%prime[i]==0)
			    return false;
		}
		return true;
	}
}

void build_prime()
{
	len=0;
	fill(primeornot,primeornot+1000000,true);
	
	primeornot[0]=false;
	primeornot[1]=false;
	
	for(int i=2;i<=sqrt(1000000);i++)
	{
		if(primeornot[i])
		    for(int j=i*i;j<=1000000;j+=i)
		        {
					primeornot[j]=false;
			    }

	}
	
	for(int i=0;i<1000000;i++)
	{
		if(primeornot[i])
		{
			prime[len++]=i;
		}
	}
	
}


void print_factors(long long int n)
{
	list<long long int> factors;
	
	for(long long int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(!isprime(i))
				factors.push_back(i);
			if(n/i!=i)
			    if(!isprime(n/i))
					factors.push_back(n/i);
		}
	}

	if(factors.size()==0)
		printf("0\n");
	else
	{
	

	factors.sort();
	printf("%d ",factors.size());

	for(list<long long int>::iterator i = factors.begin();i!=factors.end();i++)
	{
		printf("%lld ",*i);
	}
	printf("\n");
	}
	
}


int main()
{
	int t;
	scanf("%d",&t);
	long long int arr[t];
	//long long int max=0;

	int i=0;
	
	while(t--)
	{
		scanf("%lld",&arr[i++]);
//		if(arr[i++]>max)
//		    max = arr[i-1];
	}
	
	build_prime();
	//printf("NO problem in building\n");

	for(int j=0;j<i;j++)
	{
		if(arr[j]%2==1)
		    printf("0\n");
		else
			print_factors(arr[j]/2);
	}
	//return 0;
	system("PAUSE");

}
