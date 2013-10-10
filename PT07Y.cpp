/*
Checking a graph for being a tree
Need to check only connected graph and n-1 edges... automatically a tree
BFS checks the first and second one is checked at time of input
*/

#include<cstdio>
#include<cstdlib>
#include<list>
#include<queue>
using namespace std;
bool istree(list<int> adj[],int n)
{
	int status[n];
	fill(status,status+n,0);
	
	int distance[n];
	fill(distance,distance+n,-1);
	
	queue<int> bfs;
	bfs.push(0);
	status[0]=1;
	distance[0]=0;
	
	while(!bfs.empty())
	{
		int current = bfs.front();
		list<int>::iterator x = adj[current].begin();
		for(;x!=adj[current].end();x++)
		{
			if(status[*x]==0)
			{
				bfs.push(*x);
				status[*x]=1;
				distance[*x]=distance[current]+1;
			}
		}
		bfs.pop(); 
	}
	
	for(int i=0;i<n;i++)
	{
		if(distance[i]==-1)
			return false;
	}
	return true;
}

int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	
	list<int> adj[n];
	
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	if(istree(adj,n) && m==n-1)
		printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
