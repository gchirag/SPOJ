#include<cstdio>
#include<cstdlib>
using namespace std;

int min(int a,int b)
{
	return (a<b)? a:b;
}
int main()
{
	int n;
	scanf("%d",&n);
	char a[n];
	char c;
	int len =0;
	getchar();
	c=getchar();
	
	while(len<n)
	{
		a[len++]=c;
		c=getchar();
	}

	static short dptable[2][5001];
	int i,j,gap;
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<len;j++)
		{
			dptable[i][j]=0;
		}
	}
		
	/*
	Here, dptable[gap][starting_position] = characters to be inserted in a string with length=gap and starting at position starting_position.
	Always we need gap-1 and gap-2 answers for writing our gap values, why store the others, so keep on using nad overwriting them.
	Final answer we want is gap=len-1 and starting position = 0
	*/	
	for(gap=1;gap<len;gap++)
	{
		for(i=0,j=gap;j<len;i++,j++)
		{
			dptable[gap&1][i]= (a[i]==a[j])? dptable[(gap-2)&1][i+1]:(min(dptable[(gap-1)&1][i+1],dptable[(gap-1)&1][i])+1);
		}
	}	
	
	printf("%u\n",dptable[!(len&1)][0]);
	
	return 0;
}
