/*
Finding minimum vertex cover of a tree
Using DFS so as to start from the leaf nodes
using greedy strategy now, if you and parent are not selected, select the parent
pushed is a bool that tells since you aren't pushing anyone right now, it means all your child nodes have been examined
So we check its parent and it when its DFS has returned i.e. now
and if both aren't selected then select the parent
*/
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<list>
using namespace std;

int vertexcover(list<int> x[],int n)
{
	int* status;
	bool* matched;
	int* parent;

	status = (int*)malloc(n*sizeof(int));
	parent = (int*)malloc(n*sizeof(int));
	matched = (bool*)malloc(n*sizeof(bool));
	
	fill(status,status+n,0);
	fill(matched,matched+n,false);
	
	stack<int> dfs;
	dfs.push(0);
	status[0]=1;
	
	while(!dfs.empty())
	{
		bool pushed=false;
		int current = dfs.top();
		list<int>::iterator i;
		for(i= x[current].begin(); i!=x[current].end();i++)
		{
			if(status[*i]==0)
			{
				parent[*i]=current;
				dfs.push(*i);
				status[*i]=1;
				pushed = true;
			}
		}
		if(!pushed)
		{
			if(matched[parent[current]]==0 && matched[current]==0)
			{
				if(current!=0)
					matched[parent[current]]=1;
			}
			dfs.pop();
		}
	}
	
	int ans=0;
	for(int j=0;j<n;j++)
	{
		if(matched[j])
			ans++;
	}

		
	for(int j=0;j<n;j++)
	{
		x[j].erase(x[j].begin(),x[j].end());
	}
		
	return ans;
}

int main()
{
	int n;
	scanf("%d",&n);
	list<int> adj[n];
	int a,b;
	
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	printf("%d\n",vertexcover(adj,n));
	return 0; 
}
