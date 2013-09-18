#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	
	double a,b,c,d,s;
	while(t--)
	{
		scanf("%lf",&a);
		scanf("%lf",&b);
		scanf("%lf",&c);
		scanf("%lf",&d);
	
	    
	
	s = (a+b+c+d)/2;
	//printf("%lf---%lf---%lf---%lf----%lf\n",a,b,c,d,s);
	printf("%0.2lf\n",sqrt((s-d)*(s-a)*(s-b)*(s-c)));
	}
	system("PAUSE");
	
}
