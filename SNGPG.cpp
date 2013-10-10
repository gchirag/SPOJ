#include<cstdio>
#include<cstdlib>
using namespace std;

int returnval(int a,int b)
{
	int count=0;
	if(a<=0 && b>=0)	count++;
	if(a<=1 && b>=1)	count++;
	if(a<=2 && b>=2)	count++;
	if(a<=3 && b>=3)	count++;

return count;
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",returnval(a,b));
	}
	return 0;
}
