#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);	
}

int getgcd(int a,char* b,int len)
{
	int len_gcd = ceil(log10(len));
	int val = 0;
	for(int i=0;i<len_gcd;i++)
	{
		val = val*10 + b[i]-'0';
	} 
	
	int rem_start = val%a;
	
	for(int i=len_gcd;i<len;i++)
	{
		rem_start = ((rem_start*10)+b[i]-'0')%a;
	} 
	
	return gcd(a,rem_start);
	
}


int main()
{
	int t;
	int a;
	char b[252];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		scanf("%s",b);
		if(a!=0)
			printf("%d\n",getgcd(a,b,strlen(b)));
		else
		{
			for(int i=0;i<strlen(b);i++)
			{
				printf("%c",b[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
