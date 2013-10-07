#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int t,n,result;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		result = n;
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
				result-=result/i;
			while(n%i==0)
				n=n/i;
		}
		if(n>1) result-=result/n;
		printf("%d\n",result);
	}
	return 0;
}
