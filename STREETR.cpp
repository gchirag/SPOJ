#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else if(b>a) return gcd(a,b%a);
	else return gcd(b,a%b);
	
}
int main()
{
	int n; scanf("%d",&n);
	int a[n];
	scanf("%d",&a[0]);
	scanf("%d",&a[1]);
	int gcdval=abs(a[0]-a[1]);
	
	for(int i=2;i<n;i++)
	{
		scanf("%d",&a[i]);
		gcdval = gcd(a[i]-a[i-1],gcdval);	
	}
	
	printf("%d\n",(a[n-1]-a[0])/gcdval + 1 - n);
	return 0;
	
}
