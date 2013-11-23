#include<cstdio>
#include<cstdlib>
using namespace std;

int T[30];
void build_ans()
{
	T[0]=1;T[1]=0;T[2]=3;T[3]=0;
	for(int i=4;i<31;i++)
	{
		T[i]=4*T[i-2]-T[i-4];
	}
}
int main()
{
	build_ans();
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		printf("%d\n",T[n]);
		scanf("%d",&n);
	}	
	return 0;
}
