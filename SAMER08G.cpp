#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	bool flag;
	scanf("%d",&n);
	while(n!=0)
	{
		flag = false;
		int* arr = (int*)malloc(sizeof(int)*n);
		int* arr2 = (int*)malloc(sizeof(int)*n);
		int* ans = (int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
		{
			ans[i]=-1;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",arr+i,arr2+i);
		}
		for(int i=0;i<n;i++)
		{
			if(i+arr2[i]>=0 && i+arr2[i]<n)
			{
				if(ans[i+arr2[i]]!=-1)
				{
					flag = true;
					break;
				}
				else
				{
					ans[i+arr2[i]]=arr[i];
				}
			}
			else
			{
				flag = true;
				break;
			}
		}
		if(flag)
			printf("-1\n");
		else
		{
			for(int i=0;i<n-1;i++)
			{
				printf("%d ",ans[i]);
			}
			printf("%d\n",ans[n-1]);
		}
		free(ans);
		free(arr);
		free(arr2);
		scanf("%d",&n);
	}
	return 0;
}
