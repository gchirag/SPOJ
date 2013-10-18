#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct edge
{
	int u;
	int v;
	int weight;
};
struct graph
{
	int v;
	int e;
	edge* edges;
};

struct subset
{
	int parentno;
	int rank;
};

bool comparer(edge x,edge y)
{
	return x.weight<y.weight;
}

int find(subset* sets,int i)
{
	if(sets[i].parentno!=i)
		sets[i].parentno = find(sets,sets[i].parentno);
	
	return sets[i].parentno;
}

int union_op(subset* sets,int x,int y)
{
	int xroot = x;
	int yroot = y;
	
	if(sets[xroot].rank<sets[yroot].rank)
	{
		sets[xroot].parentno = yroot;
	}
	else if(sets[xroot].rank>sets[yroot].rank)
	{
		sets[yroot].parentno = xroot;
	}
	else
	{
		sets[xroot].rank++;
		sets[yroot].parentno = xroot;
	} 
}

int main()
{
	int n,m,x,y,z;
	scanf("%d%d",&n,&m);
	
	graph* givengraph = (graph*) malloc(sizeof(graph));
	givengraph->edges = (edge*) malloc(sizeof(edge)*m);
	
	givengraph->e = m;
	givengraph->v = n;
	
	edge mst[n-1];
	
	int count = 0;

	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		givengraph->edges[i].u = x-1;
		givengraph->edges[i].v = y-1;
		givengraph->edges[i].weight = z;
	}
	
	sort(givengraph->edges,givengraph->edges+m,comparer);
	
//	for(int i = 0;i<m;i++)
//	{
//		//mstweight+=mst[i].weight;
//		printf("Edge applied for mst: Vertex1 - %d, Vertex2 - %d, Weight - %d\n",givengraph->edges[i].u,givengraph->edges[i].v,givengraph->edges[i].weight);
//	}
//	
		
	subset sets[n];
	
	for(int i=0;i<n;i++)
	{
		sets[i].parentno = i;
		sets[i].rank = 0;
	}	
	
	int edge_iter = 0;
	int len = 0;

	while(len<n-1)
	{
		edge temp = givengraph->edges[edge_iter++];
		int setu = find(sets,temp.u);
		int setv = find(sets,temp.v);
		
		if(setu!=setv)
		{
			mst[len++] = temp;
			union_op(sets,setu,setv);
		}	
	}
	
	long long int mstweight = 0;
	for(int i=0;i<len;i++)
	{
		mstweight+=mst[i].weight;
		//printf("Edge shortlisted for mst: Vertex1 - %d, Vertex2 - %d, Weight - %d\n",mst[i].u,mst[i].v,mst[i].weight);
	}
	
	printf("%lld\n",mstweight);
	
	
//	mst[0].u = graph[0].u;
//	mst[0].v = graph[0].v;
//	mst[0].weight = graph[0].weight;
	
//	for(int i=0;i<m;i++)
//	{
//		printf("Edge %d---%d with weight %d\n",graph[i].u,graph[i].v,graph[i].weight);
//	}

//	int mstweight = 0;

//	int len = 1;
//	
//	for(int i=0;i<m;i++)
//	{
//		if(len==n-1)
//			break;
//	
//		mst[len].u = graph[i].u;
//		mst[len].v = graph[i].v;
//		mst[len++].weight = graph[i].weight;
//		
//		if(!iscycle(mst,len))
//		{
//			mstweight += mst[len-1].weight; 
//		}
//	}

//	for(int i=0;i<m;i++)
//	{
//		if(count==n)
//			break;
//		if(done[graph[i].u] && done[graph[i].v])
//			continue;
//		else if (done[graph[i].u] && !done[graph[i].v])
//		{
//			count++;
//			done[graph[i].v]=true;
//			mstweight += graph[i].weight; 
//		}
//		else if (!done[graph[i].u] && done[graph[i].v])
//		{
//			count++;
//			done[graph[i].u]=true;
//			mstweight += graph[i].weight; 
//		}
//		else if (!done[graph[i].u] && !done[graph[i].v])
//		{
//			count+=2;
//			done[graph[i].u]=true;
//			done[graph[i].v]=true;
//			mstweight += graph[i].weight; 
//		}
//	}
	
//	printf("%d\n",mstweight);
	
	
	return 0;
}






