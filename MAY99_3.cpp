#include<cstdio>
#include<cstdlib>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	int t,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&z);
		
		if(z>x && z>y)
		{
			printf("NO\n");		
			continue;
		}
		if(y>x)
			{
			if(z%gcd(x,y%x)==0)
				printf("YES\n");
			else printf("NO\n");
			}
		else
			{
			if(z%gcd(y,x%y)==0)
				printf("YES\n");
			else printf("NO\n");	
			}
	}
	return 0;
}
