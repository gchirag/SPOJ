#include<cstdio>
#include<cstdlib>
#include<list>
using namespace std;

long long int arr[500001];
bool flag[3500000];

void build_sequence()
{
	fill(flag,flag+3500000,false);
	flag[0]=true;
	arr[0]=0;
	
	for(int i=1;i<=500000;i++)
	{
		if(arr[i-1]-i>0 && !flag[arr[i-1]-i])
		{
			arr[i]=arr[i-1]-i;
			flag[arr[i-1]-i]=true;
			
		}
		else
		{
			arr[i]=arr[i-1]+i;
			flag[arr[i-1]+i]=true;
		}
		
	}
	
	
}

int main()
{
	build_sequence();
	int x;
	scanf("%d",&x);
	while(x!=-1)
	{
		printf("%lld\n",arr[x]);
		scanf("%d",&x);
	}
	return 0;
}
