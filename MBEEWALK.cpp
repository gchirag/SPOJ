#include<stdio.h>
#include<stdlib.h>

int ans[15];
int ways[15][17][17];
int i,j,k;

void build_ans()
{
	ans[0]=1;
	ways[0][8][8]=1;
	
	for(i=1;i<15;i++)
	{
		for(j=1;j<17;j++)
		{
			for(k=1;k<17;k++)
			{
				ways[i][j][k] = ways[i-1][j][k+1] + ways[i-1][j][k-1]+ways[i-1][j+1][k]+ways[i-1][j+1][k-1]+ways[i-1][j-1][k]+ways[i-1][j-1][k+1];
			}
		}
		ans[i]=ways[i][8][8];
	}
}


int main()
{
	build_ans();
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);		
	}
	return 0;
}


