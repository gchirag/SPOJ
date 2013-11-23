#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct activity
{
	int start;
	int end;
};

bool comparer(activity a1,activity a2)
{
	if(a1.end==a2.end)
		return a1.start<a2.start;
	else return a1.end<a2.end;
}


int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		activity* arr = (activity*)malloc(sizeof(activity)*n);
		
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&arr[i].start,&arr[i].end);
		}
		
		sort(arr,arr+n,comparer);
		
		int count =1;
		int prevfinish = arr[0].end;
		for(int i=1;i<n;i++)
		{
			if(arr[i].start>=prevfinish)
			{
				count++;
				prevfinish=arr[i].end;
			}
		}
		
		printf("%d\n",count);
		free(arr);
	}
	return 0;
}
