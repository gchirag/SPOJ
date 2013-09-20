#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int countsets(int* a,int n)
{
	int count=0;
	int chosen[n];
	fill(chosen,chosen+n,0);
	
	for(int i=0;i<n;i++)
	{
		if(chosen[i]==0)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j]>2*a[i]) break;
				else if(a[j]==2*a[i] && chosen[j]==0)
				{
					chosen[i]=1;
					chosen[j]=1;
					count++;
					break;
				}
				else continue;
			}
		}
	}
	return count;
}

int main()
{
	
	int t;
	scanf("%d",&t);
	int n;
	
	while(t--)
	{
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		sort(a,a+n);
		
		printf("%d\n",countsets(a,n));
	}
}
