#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n,p,ans;
	scanf("%d",&n);
	scanf("%d",&p);
	ans = p;
	n--;
	while(n--)
	{
		scanf("%d",&p);
		ans = ans^p;	
	}
	printf("%d\n",ans);
return 0;
}
