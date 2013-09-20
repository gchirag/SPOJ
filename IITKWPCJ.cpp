#include<cstdio>
#include<cstdlib>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
bool checkrep(char* str,int len,int k)
{
	for(int i=0;i<len;i++)
	{
		if(str[i]!=str[i%k])
		    return false;
	}
	return true;
}

void checkpower(char* str1,char* str2,int len1,int len2)
{
	int k =  (len1>len2)? gcd(len1,len2):gcd(len2,len1);
	//printf("gcd of length is %d\n",k);
	bool a=true;
	
	for(int i=0;i<k;i++)
	{
		if(str1[i] != str2[i])
		    a = false;
	}
	
	if(checkrep(str1,len1,k) && checkrep(str2,len2,k) && a)
	    printf("YES\n");
	else printf("NO\n");
}


int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	
	while(t--)
	{
		char str1[100001];
		char str2[100001];
		char c;
		
		int i=0;
		while((c=getchar())!=' ')
		{
			str1[i++]=c;
		}
		str1[i]='\0';
		
		int len1 = i;

		i=0;
		
		while((c=getchar())!='\n' && c!=EOF)
		{
			str2[i++]=c;
		}
		str2[i]='\0';

		int len2 = i;

		//printf("Strings are %s and %s and their lengths are %d and %d\n",str1,str2,len1,len2);
		
		checkpower(str1,str2,len1,len2);
		
	}

	return 0;
}
