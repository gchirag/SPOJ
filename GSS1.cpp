#include<cstdlib>
#include<cmath>
#include<cstdio>
using namespace std;

#define max(a,b) (a>b)? a:b

struct node
{
	int sum,bestprefix,bestsuffix,bestsum;
};

void initialize(int root,int* arr, node* T,int n,int left,int right,int maxind)
{
	if(left==right)
	{
		T[root].sum = arr[left];
		T[root].bestsum = arr[left];
		T[root].bestprefix = arr[left];
		T[root].bestsuffix = arr[left];
	}
	else
	{
		initialize(2*root,arr,T,n,left,(left+right)/2,maxind);
		initialize(2*root+1,arr,T,n,(left+right)/2+1,right,maxind);
		
		T[root].sum = T[2*root].sum + T[2*root+1].sum;
		T[root].bestprefix = max(T[2*root].sum+T[2*root+1].bestprefix,T[2*root].bestprefix);
		T[root].bestsuffix = max(T[2*root+1].sum+T[2*root].bestsuffix,T[2*root+1].bestsuffix);
		//printf("left bestsum = %d, right bestsum = %d\n",T[2*root].bestsuffix,T[2*root+1].bestprefix);
		T[root].bestsum = max( (max(T[2*root].bestsum,T[2*root+1].bestsum)),T[2*root].bestsuffix+T[2*root+1].bestprefix);
		//printf("bestsum = %d\n",T[root].bestsum);
			
	}
}
void query(node& temp,int root,int left,int right,int x,int y,node* T)
{
	if(left==x && right==y)
	{
		temp = T[root];
		return;
	}
	int mid = (left+right)/2;
	if(y<=mid) 
		query(temp,2*root,left,mid,x,y,T);
	else if(x>mid) 
		query(temp,2*root+1,mid+1,right,x,y,T);
	else
	{
		node l,r;
		query(l,2*root,left,mid,x,mid,T);
		query(r,2*root+1,mid+1,right,mid+1,y,T);
		temp.sum = l.sum+r.sum;
		temp.bestprefix = max(l.sum+r.bestprefix,l.bestprefix);
		temp.bestsuffix = max(r.sum+l.bestsuffix,r.bestsuffix);
		temp.bestsum = max( (max(l.bestsum,r.bestsum)),l.bestsuffix+r.bestprefix);	
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int maxind = 2*(int)pow(2,(int)log2(n)+1);
	node T[maxind];
	
	int* arr = (int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	for(int i=0;i<maxind;i++)
	{
		T[i].bestsum=0;
		T[i].bestprefix=0;
		T[i].bestsuffix=0;
		T[i].sum=0;
	}
	initialize(1,arr,T,n,0,n-1,maxind);
	//
//	for(int i=0;i<maxind;i++)
//	{
//		printf("%d--->%d,%d,%d,%d\n",i,T[i].bestsum,T[i].sum,T[i].bestprefix,T[i].bestsuffix);
//	}
//	
	
	int m;
	scanf("%d",&m);
	int x,y;
	while(m--)
	{
		node temp;
	
		scanf("%d%d",&x,&y);
		query(temp,1,0,n-1,x-1,y-1,T);
		
		printf("%d\n",temp.bestsum);
	}
	return 0;
}
