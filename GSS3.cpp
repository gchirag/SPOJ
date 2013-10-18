#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}

struct node{
	int sum,bestsum,bestprefix,bestsuffix;
};

void initialize(int root,node* T,int* arr,int left,int right)
{
	if(left==right)
	{
		T[root].sum = arr[left];T[root].bestsum= arr[left];  T[root].bestprefix = arr[left];T[root].bestsuffix = arr[left];
		return;
	}
	else
	{
	
	int m = (left+right)/2;
	int l = 2*root;
	int r = l+1;
	initialize(l,T,arr,left,m);
	initialize(r,T,arr,m+1,right);
	
	T[root].sum = T[l].sum + T[r].sum;
	T[root].bestsum = max( T[l].bestsum, max(T[r].bestsum,T[l].bestsuffix+T[r].bestprefix) );
	T[root].bestprefix = max(T[l].sum+T[r].bestprefix,T[l].bestprefix);
	T[root].bestsuffix = max(T[r].sum+T[l].bestsuffix,T[r].bestsuffix);
	}
}

void query(node& temp,int root,int left,int right,node* T,int x,int y)
{
	//printf("%d  %d\n",x,y);
	if(x==left && y==right)
	{
		temp = T[root];
		return;
	}
	int mid = (left+right)/2;
	if(y<=mid)
		query(temp,2*root,left,mid,T,x,y);
	else if(x>mid)
		query(temp,2*root+1,mid+1,right,T,x,y);	
	else
	{
		node l,r;	
		query(l,2*root,left,mid,T,x,mid);
		query(r,2*root+1,mid+1,right,T,mid+1,y);
		temp.sum = l.sum+r.sum;
		temp.bestsum = max(l.bestsum, max(r.bestsum,l.bestsuffix+r.bestprefix) );
		temp.bestprefix = max(l.bestprefix,l.sum+r.bestprefix);
		temp.bestsuffix = max(r.bestsuffix,r.sum+l.bestsuffix);
	}
}
void update(int root,int left,int right,node* T,int pos,int val)
{
	//printf("Update mein hu %d--%d\n",left,right);
	
//	if(right<pos||left>pos)
//		return;
	
	if(right==left && left == pos)
	{
		//printf("Changing value of index %d from %d to %d\n",left,T[left].sum,val);
		T[root].bestsum = val;
		T[root].sum = val;
		T[root].bestprefix = val;
		T[root].bestsuffix = val;
		return;
	}	
	
	int mid = (left+right)/2;
	int l=2*root;
	int r=l+1;

	if(pos<=mid)
		update(l,left,mid,T,pos,val);
	else
	{
		//printf("Calling update2 %d %d\n",mid+1,right );
		update(r,mid+1,right,T,pos,val);
	}
	T[root].sum = T[l].sum + T[r].sum;
	T[root].bestsum = max( T[l].bestsum, max( T[r].bestsum, T[l].bestsuffix+T[r].bestprefix) );
	T[root].bestprefix = max( T[l].sum+T[r].bestprefix , T[l].bestprefix );
	T[root].bestsuffix = max( T[r].sum+T[l].bestsuffix, T[r].bestsuffix);
}
int main()
{
	int n,p,x,y;
	scanf("%d",&n);
	int* arr = (int*) malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	
	int m;
	scanf("%d",&m);
	int maxind=2*(int)(pow(2,(int)log2(n)+1));
	
	node T[maxind];
	node temp;
	for(int i=1;i<maxind;i++)
	{
		T[i].bestsum = 0;
		T[i].sum = 0;
		T[i].bestprefix = 0;
		T[i].bestsuffix = 0;
	}
	
	initialize(1,T,arr,0,n-1);
//	for(int i=1;i<maxind;i++)
//	{
//		//printf("%d-->%d %d %d %d\n",i,T[i].bestsum,T[i].sum,T[i].bestprefix,T[i].bestprefix);
//	}



	while(m--)
	{
		scanf("%d%d%d",&p,&x,&y);
		
		if(p==1)
		{
			query(temp,1,0,n-1,T,x-1,y-1);
			printf("%d\n",temp.bestsum);
		}
		else if(p==0)
		{
			arr[x-1] = y;
			update(1,0,n-1,T,x-1,y);
			
//				for(int i=1;i<maxind;i++)
//				{
//					//printf("%d-->%d %d %d %d\n",i,T[i].bestsum,T[i].sum,T[i].bestprefix,T[i].bestprefix);
//				}

		}
	}
	
	
	return 0;
}
