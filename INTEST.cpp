#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n,k,x,count=0;
	scanf("%d%d",&n,&k);
	while(n--)
	{
		scanf("%d",&x);
		if(x%k==0)	count++;
	}
	printf("%d\n",count);
}
