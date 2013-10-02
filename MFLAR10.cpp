#include<cstdio>
#include<cstdlib>
#include<ctype.h>
using namespace std;

int main()
{
	char c,prev;
	char start;
	
	while((c=getchar())!='*')
	{
		start = tolower(c);
		prev = start;
		bool ans = true;
		
		while((c=getchar())!='\n')
		{
			c=tolower(c);
			if(prev==' ')
				{
					if(c!=start)
						ans=false;
				}
			prev=c;	
		}
		if(ans)
			printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
