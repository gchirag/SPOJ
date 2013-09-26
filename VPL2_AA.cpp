#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int k = t;
	int x,x1,x2,time;
	while(t--)
	{
		scanf("%d",&x1);
		scanf("%d",&x2);
		scanf("%d",&time);
		scanf("%d",&x);
		
		double ans = time*log(x/(double)x1)/log(x2/(double)x1);
		printf("Scenario #%d: %0.2lf\n",k-t,round(ans*100)/100);
		
	}
	return 0;
}
