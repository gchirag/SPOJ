#include<cstdio>
#include<cstdlib>
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
		//printf("HAHA\n");
	}
	
	return left;
}

int lis(int* a,int n)
{
	int best[n];
	int len;
	best[0]=a[0];
	len =1;
	
	for(int i=1;i<n;i++)
	{
		if(a[i]<best[0])
		    best[0]=a[i];
		else if(a[i]>best[len-1])
		    best[len++]=a[i];
		else
		    best[search(best,0,len-1,a[i])] = a[i];
	}
	
	return len;

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
		
		printf("%d\n",n-lis(a,n));
	}
	system("PAUSE");
	return 0;
}
