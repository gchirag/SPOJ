#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int min(int a,int b,int c)
{
	return (a<b)? ((a<c)? a:c):((b<c)? b:c);
}
int main()
{
	int t;
	scanf("%d",&t);
	char s1[2001],s2[2001];
	
	static int E[2001][2001];
		
	while(t--)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		
		
		int len1=strlen(s1),len2=strlen(s2);
		//printf("%d %d\n",len1,len2);
		len1++;len2++;
		for(int i=0;i<len1;i++)
		{
			E[i][0]=i;
		}
		for(int i=0;i<len2;i++)
		{
			E[0][i]=i;
		}
		for(int i=1;i<len1;i++)
		{
			for(int j=1;j<len2;j++)
			{
				E[i][j] = min(E[i-1][j]+1,E[i][j-1]+1,((s1[i-1]==s2[j-1])? E[i-1][j-1]:(E[i-1][j-1]+1)));
			}
		}
		
//		for(int i=0;i<len1;i++)
//		{
//			for(int j=0;j<len2;j++)
//			{
//				printf("%d\t",E[i][j]);
//			}
//			printf("\n");
//		}
		printf("%d\n",E[len1-1][len2-1]);
	}
	return 0;
}
