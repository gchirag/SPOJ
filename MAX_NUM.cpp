#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int n[100001];
	int count[10];
	int sum[10];
	int currsum;
	char c;
	int len;
	stack<int> s;

	while(t--)
	{

		len=0;
		
		getchar();		
		
		while((c=getchar())!=' ')
		{
			n[len++]=c-'0';
		}
		
		int digit;
		scanf("%d",&digit);
		
		s.push(n[0]);
		
		for(int i=1;i<len;i++)
		{
			while(!s.empty() && s.size()+len-i>len-digit && n[i]>s.top())
			{
				s.pop();
			}
			s.push(n[i]);
		}
		
		int len2=s.size()-1;
		int* ans = (int*) malloc(sizeof(int)*(len2+1));
		
		for(int i=0;i<=len2;i++)
		{
			ans[len2-i]=s.top();
			s.pop();
		}
		
		for(int i=0;i<len-digit;i++)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
		free(ans);
	}
	return 0;
}
