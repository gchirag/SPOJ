#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);	
}

int main()
{
	char str[21];
	scanf("%s",str);
	
	while(str[0]!='*')
	{
		int len = strlen(str);
		long long int lcm = 1;
		
		for(int i=0;i<len;i++)
		{
			if(str[i]=='Y')
			{
				lcm = lcm * (i+1) / gcd(lcm,i+1);
			}
		}
		
		bool flag = false;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='N')
			{
				if(lcm%(i+1)==0)
				{
					flag = true;
					break;
				}
			}
		}
		
		if(!flag)
			printf("%lld\n",lcm);
		else
			printf("-1\n");
		
		scanf("%s",str);
		
	}
	
	return 0;
}
