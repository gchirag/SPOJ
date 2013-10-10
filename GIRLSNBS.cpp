#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n,m,temp;
	scanf("%d%d",&n,&m);
	
	while(!(n==-1 && m==-1))
	{
		if(n<m)
		{
			temp = n;
			n=m;
			m=temp;
		}
		
 		 printf("%d\n",(n+m)/(m+1));

		scanf("%d%d",&n,&m);
	}
	return 0;
}
