/*
Length of the longest path in a tree
2 BFS's needed
Lastguy of first BFS to find one end of the longest path
And Lastguy of the second BFS starting from the previous Lastguy will be the endpoint of the longest path
Note distances of points during second BFS
*/

#include<cstdio>
#include<cstdlib>
#include<queue>
#include<list>
using namespace std;

int length_of_longest_path(list<int> x[],int n)
{
	int status[n];
	fill(status,status+n,0);
	
	queue<int> bfs;
	bfs.push(0);
	status[0]=1;
	int lastguy;
	
	while(!bfs.empty())
	{
		lastguy = bfs.front();
		list<int>::iterator iter;
		for(iter=x[lastguy].begin();iter!=x[lastguy].end();iter++)
		{
			if(status[*iter]==0)
			{
				bfs.push(*iter);
				status[*iter]=1;
			}
		}
		bfs.pop();
	}
	
	fill(status,status+n,0);
	
	bfs.push(lastguy);
	int ans=0;
	int distance[n];
	distance[lastguy]=0;
	
	while(!bfs.empty())
	{
		lastguy = bfs.front();
		list<int>::iterator iter;
		for(iter=x[lastguy].begin();iter!=x[lastguy].end();iter++)
		{
			if(status[*iter]==0)
			{
				bfs.push(*iter);
				status[*iter]=1;
				distance[*iter] = distance[lastguy]+1;
			}
		}
		bfs.pop();
	}
	
	return distance[lastguy];
	
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
	printf("%d\n",length_of_longest_path(adj,n));
	
	return 0;
}
