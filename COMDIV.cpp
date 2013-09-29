#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	if(b>a)
		return gcd(a,b%a);
	else return gcd(b,a%b);
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		int g = gcd(a,b);
		
		int count = 0;
		
		for(int i=1;i<sqrt(g);i++)
		{
			if(g%i==0)
				count+=2;
		}
		
		if(g==(int)sqrt(g)*(int)sqrt(g))
			count++;
		printf("%d\n",count);
	}
	return 0;
}
