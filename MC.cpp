/*
Each string should be reduce to the LCS to make equal ... delete the rest
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define max(a,b) (a>b)? a:b

char a[1002];
char b[1002];
short dp[1002][1002];

int costcalculate(int lena,int lenb)
{
	for(int i=0;i<=lena;i++)
	{
		for(int j=0;j<=lenb;j++)
		{
			dp[i][j] = 0;
		}
	}

	int len=0;
	
	for(int i=0;i<=lena;i++)
	{
		for(int j=0;j<=lenb;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}	
//	for(int i=0;i<=lena;i++)
//	{
//		for(int j=0;j<=lenb;j++)
//		{
//			printf("%u\t",dp[i][j]);
//		}
//		printf("\n");
//	}
//	
//	printf("LCS is %d\n",dp[lena][lenb]);
	
printf("%d\n",15*(lena-dp[lena][lenb])+30*(lenb-dp[lena][lenb]));
}



int main()
{
	while(1)
	{
		scanf("%s",a);
		if(a[0]=='#')
			break;
		scanf("%s",b);
		//printf("%d\n",strlen(a));
		costcalculate(strlen(a),strlen(b));
		//printf("%d\n",costcalculate(strlen(a),strlen(b)));
	}	
	return 0;
}
