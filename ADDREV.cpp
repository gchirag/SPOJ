#include<cstdio>
#include<cstdlib>
using namespace std;

long long int reverse(long long int a)
{
	long long int result;
	result=0;
	while(a!=0)
	{
		result*=10;
		result+=a%10;
		a/=10;
	}
	return result;
		
}

int main()
{
	int t;
	scanf("%d",&t);
	long long int a,b,ans;
	while(t--)
	{
		scanf("%lld",&a);
		scanf("%lld",&b);
		
		ans = reverse(reverse(a)+reverse(b));
		printf("%lld\n",ans);
	}
	return 0;
}
