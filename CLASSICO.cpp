/*
LOGIC of MAX_NUM

Deleting k digits from n -- output the largest possible answer

Used stack --> push elements of array continuously while deleting smaller elements till possible length
That is, it is not possible to delete an element from the stack if the remaining elements of the array and the current stack size < digits(n)-k
Because eventually we want to form an (digits(n) - k) digit number

Here we have to delete (given no. of players -11) values from the array
Again go on adding and deleting in the stack till the total players can only be made 11 if everything else is used
*/

#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int n[2001];
	int len;
	stack<int> s;
	int p;
	int tcopy=t;
	while(t--)
	{
		scanf("%d",&p);
		
		len=p;
		
		getchar();		
		
		for(int i=0;i<p;i++)
		{
			scanf("%d",&n[i]);
		}
		
		int digit=len-11;
		
		if(p<11)
		{
			printf("Case %d: go home!\n",tcopy-t);
			continue;
		}
			
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
		
		printf("Case %d: ",tcopy-t);
		
		for(int i=0;i<len-digit-1;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("%d",ans[len-digit-1]);
		printf("\n");
		free(ans);
	}
	return 0;
}
