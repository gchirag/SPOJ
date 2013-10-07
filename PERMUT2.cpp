#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		int arr[n];
		int arr_perm[n];
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			arr_perm[arr[i]-1]=i+1;
		}
		
		
		
		bool flag =true;
		
		for(int i=0;i<n;i++)
		{
			if(arr_perm[i]!=arr[i])
				{
				flag=false;
				break;
				}
		}
		
		if(flag)
			printf("ambiguous\n");
		else printf("not ambiguous\n");
		
		scanf("%d",&n);
	}
}
