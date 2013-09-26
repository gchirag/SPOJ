#include<cstdio>
#include<cstdlib>
using namespace std;

long long int power(long long int a,int x)
{
	long long int result=1;
	
	while(x>0)
	{
		if(x%2==1)
			result = (result*a)%10000007;
		a = (a*a)%10000007;
		
		x >>= 1; 
	}
	return result;
}

long long int inverse(long long int a)
{
	return power(a,9988439)%10000007;
}

long long int choose(long long int a,long long int b)
{
	if(b>a) return -1;
	if(b>a/2)
		b = a-b;
	
	long long int ans=1;
	for(int k=1;k<=b;k++)
	{
		ans = ((ans*a)%10000007 * inverse(k)%10000007)%10000007;
		a--;
	}	
	return ans%10000007;
}

int main()
{
	long long int n,r;
	scanf("%lld",&n);
	scanf("%lld",&r);
	
	printf("%lld\n",choose(n-1,r-1));
	
	return 0;
}
