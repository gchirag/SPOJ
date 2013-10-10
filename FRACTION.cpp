#include<cstdio>
#include<cstdlib>
using namespace std;

short ansa[7700000];
short ansb[7700000];
	
void build_farey(int n,short int* ansa,short int* ansb)
{
	int a=0,b=1,c=1,d=n,len=0,k,t1,t2;
	ansa[len]=a;
	ansb[len++]=b;
	
	while(c<=n)
	{
		k = (n+b)/d;
		t1 = k*c - a;
		t2 = k*d - b;
		a = c;
		b = d;
		c = t1;
		d = t2;
		ansa[len]=a;
		ansb[len++]=b;
	}
}


int main()
{
	int t,n,m,k;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		build_farey(n,ansa,ansb);
		while(m--)
		{
			scanf("%d",&k);
			printf("%hu/%hu\n",ansa[k-1],ansb[k-1]);
		}
	}
	return 0;
}
