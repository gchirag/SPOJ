#include<cstdlib>
#include<cstdio>
#include<deque>
using namespace std;

void printkbest(int *arr,int n,int k)
{
	deque<int> myqueue(k);
	
	for(int i=0;i<k;i++)
	{
		while((!myqueue.empty()) && arr[i]>=arr[myqueue.back()])
		{
			myqueue.pop_back();
		}
		
		myqueue.push_back(i);
	}
	
	for(int i=k;i<n;i++)
	{
		printf("%d ",arr[myqueue.front()]);
		while((!myqueue.empty()) && myqueue.front()<=i-k)
		{
			myqueue.pop_front();
		}
        while((!myqueue.empty()) && arr[i]>=arr[myqueue.back()])
		{
			myqueue.pop_back();
		}

		myqueue.push_back(i);
	}

	printf("%d",arr[myqueue.front()]);
}

int main()
{
	int n,k;
	scanf("%d",&n);
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	scanf("%d",&k);

	printkbest(arr,n,k);

	return 0;
	
}
