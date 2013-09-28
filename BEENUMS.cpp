#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int k;
	
	while(!(n==-1))
	{
		
		k=6;
		n=n-1;
		while(n>0)
		{
			n-=k;
			k=k+6;
		}
			
		if(n==0)
			printf("Y\n");
		else printf("N\n");
		
		scanf("%d",&n);
	}
	
	
}
