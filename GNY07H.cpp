#include<cstdio>
#include<cstdlib>
using namespace std;

/* Detailed solution http://stackoverflow.com/questions/16388579/spoj-m3tile-solution-explanation */

int T[25];
int K[25];

void build_ans()
{
	T[0]=1;T[1]=1;T[2]=5;
	K[0]=0;K[1]=1;K[2]=1;
	
	for(int i=3;i<25;i++)
	{
		T[i]=2*T[i-1]+2*T[i-2]-T[i-3]+K[i-1]-K[i-2];
		K[i]=T[i-1]+K[i-2];
	}
	
}
int main()
{
	build_ans();
	
	int t,w,tcopy;
	scanf("%d",&t);
	tcopy=t;
	while(t--)
	{
		scanf("%d",&w);
		printf("%d %d\n",tcopy-t,T[w]);
	}
	return 0;
}
