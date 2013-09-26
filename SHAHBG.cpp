#include<cstdio>
#include<cstdlib>
#include<list>
using namespace std;
bool people[20001];

int main()
{
	int n,m;
	scanf("%d",&n);
	
	fill(people,people+20001,false);
	int count =0;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&m);
		people[m]=true;
		
		if(people[m+1] && people[m-1])
		{
			printf("%d\n",count-1);
			count--;
		}
		else if(people[m+1]||people[m-1])
		{
			printf("%d\n",count);
		}
		else
		{
			printf("%d\n",count+1);
			count++;
		}

	}
	printf("Justice\n");	
	return 0;	
}
