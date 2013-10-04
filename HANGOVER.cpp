#include<cstdio>
#include<cstdlib>
using namespace std;

double ans[275];

void build_ans()
{
	double sum;
	sum=0;
	for(int i=1;i<275;i++)
	{
		sum +=1.0/(i+1);
		ans[i]=sum;
	}
}

int search(double x)
{
	int left=0,right=274;
	int middle;
	while(!(left==right))
	{
		middle=(left+right)/2;
		if(ans[middle]>=x)
			right=middle;
		else left = middle+1;
	}
	return left;
}

int main()
{
	build_ans();
	
//	for(int i=0;i<20;i++)
//	{
//		printf("%lf\t",ans[i]);
//	}
	
	double x;
	scanf("%lf",&x);
	while(x!=0)
	{
		printf("%d card(s)\n",search(x));
		scanf("%lf",&x);
	}
	
}



