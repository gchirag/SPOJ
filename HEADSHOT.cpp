#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	char* s = (char*) malloc(sizeof(char)*101);
	char c;
	int len=0;
	while((c=getchar())!='\n')
	{
		s[len++]=c;
	}
	s[len]='\0';
	//printf("string %s length %d\n",s,len);
	
	int count0 = 0, count1 = 0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0')
		{
			if(s[(i+1)%len]=='0')
				count0++;
			else count1++;
		}
	}
	
	if(count0>count1 && count1>0)
		printf("SHOOT\n");
	else if(count0<count1)
		printf("ROTATE\n");
	else printf("EQUAL\n");
	
	
	return 0;
	
}
