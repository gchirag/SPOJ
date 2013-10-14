#include<cstdio>
#include<cstdlib>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

char inputstring[7];

map<int,int> chirag;
bool homo,hetero;
int sum;


void print_status()
{
	map<int,int>::iterator iter;
	
	if(chirag.size()>1)
		hetero = true;	
	
	if(sum>chirag.size())
		homo = true;


	if(homo && hetero)
		printf("both\n");
	else if(homo && !hetero)
		printf("homo\n");
	else if(!homo && hetero)
		printf("hetero\n");
	else printf("neither\n");		
		
}
int main()
{
	int n,a;
	scanf("%d",&n);
	
	map<int,int>::iterator iter;
	bool prevhomo,prevhetero;
	sum = 0;
		
	while(n--)
	{
		scanf("%s",inputstring);
		scanf("%d",&a);
		
		//printf("%s %d\n",inputstring,a);
		homo = false;
		hetero = false;
		
		if(inputstring[0]=='i')
		{
			
			if(chirag.find(a)==chirag.end())
				chirag[a] = 1;
			else chirag[a]+=1;
			
			sum++;	
			print_status();
		}
		
		if(inputstring[0]=='d')
		{
			
			if(chirag.find(a)==chirag.end())
			{
				print_status();
				continue;
			}
			if(chirag[a]==1)
				chirag.erase(a);
			else chirag[a]-=1;
			
			sum--;
			print_status();
		}
//		printf("Size is: %d\n",chirag.size());
		
	}
	return 0;
}
