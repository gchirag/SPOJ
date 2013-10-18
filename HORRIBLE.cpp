#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
long long int T[263000][2];

void query(long long int& temp,int root,int left,int right,int x,int y,long long int lazy)
{
	//printf("%d %d\n",left,right);
	if(left==x && right==y)
	{
		temp = T[root][0]+lazy*(y-x+1);
		return;
	}
	int mid = (left+right)/2;
	if(y<=mid)
		query(temp,2*root,left,mid,x,y,lazy+T[root][1]);
	else if(x>mid)
		query(temp,2*root+1,mid+1,right,x,y,lazy+T[root][1]);
	else
	{
		long long int l,r;
		query(l,2*root,left,mid,x,mid,lazy+T[root][1]);
		query(r,2*root+1,mid+1,right,mid+1,y,lazy+T[root][1]);

		//printf("Bhai idhar 2--- %d %d\n",l,r);
		temp = l+r;
		return;
	}
	
}

//update(1,0,n-1,T,p-1,q-1,v);

void update(int root,int left,int right,int i,int j,long long int val)
{
	//printf("%d---%d---%d---%d\n",left,right,i,j);
	if(left==i && right==j)
	{
		//printf("Changing value of node %d from %d to %d\n",root,T[root],T[root]+val);
		T[root][0]+=val*(j-i+1);
		T[root][1]+=val;
		return;
	}
	
	int mid = (left+right)/2;
	if(j<=mid)
	{
		//T[root][0] += val*(j-i+1);
		update(2*root,left,mid,i,j,val);
		//T[root] = T[2*root]+T[2*root+1];	
	}
	else if(i>mid)
	{
		//T[root] += val*(j-i+1);
		update(2*root+1,mid+1,right,i,j,val);
		//T[root] = T[2*root]+T[2*root+1];
	}
	else
	{
		//T[root][0]+=val*(j-i+1);
		update(2*root,left,mid,i,mid,val);
		update(2*root+1,mid+1,right,mid+1,j,val);
		//printf("Changing value of node %d from %d to %d\n",root,T[root],T[2*root]+T[2*root+1]);
		
	}

	T[root][0] = T[2*root][0]+T[2*root+1][0]+T[root][1]*(right-left+1);
	//return;

}




int main()
{
	int t;
	int n,c,p,q,d;
	long long int v,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		
		long long int maxind = 2*(int)pow(2,(int)log2(n)+1);
		//printf("%lld\n",maxind);
		//long long int T[maxind];
		for(int i=0;i<maxind;i++)
		{
			T[i][0]=0;
			T[i][1]=0;
		}
		//printf("%d\n",n);
		while(c--)
		{
			scanf("%d",&d);
			if(d==1)
			{
				scanf("%d%d",&p,&q);
				//printf("scan done\n");
				query(ans,1,0,n-1,p-1,q-1,0);
				printf("%lld\n",ans);
			}
			else 
			{
				scanf("%d%d%lld",&p,&q,&v);	
				update(1,0,n-1,p-1,q-1,v);
			}
		}
	}
}
