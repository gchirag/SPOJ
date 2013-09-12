#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int search(int* a, int left, int right, int val)
{
	int middle;

	while(left!=right)
	{
        middle =(left+right)/2;
        if(a[middle]>=val)
	    	right = middle;
		else
			left = middle+1;
	}

	return left;
}

int stepsneeded(int* arr, int n)
{
	int sortarr[n];
    int helper[n];

	for(int i=0;i<n;i++)
	{
		sortarr[i]=arr[i];
	}

	sort(sortarr,sortarr+n);

	for (int i=0;i<n;i++)
	{
		helper[search(sortarr,0,n-1,arr[i])] = i;
	}

	int count = 1;
	int prev=0;
	
	for(int i=1;i<n;i++)
	{
		if(helper[i]>helper[i-1])
		    count++;
		else if(count>prev)
		    {
				prev=count;
				count=1;
		    }
	}

	if(count>prev)
		prev=count;

	return n-prev;
}



int main()
{
   	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}

		printf("%d\n",stepsneeded(a,n));
	}

return 0;
}
