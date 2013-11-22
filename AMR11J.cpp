#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
struct cell
{
	//char c;
	int row;
	int col;
	//int dist;	
};

bool checkvalid(int a,int b,int c,int d)
{
	if(a>=0 && a<c)
		if(b>=0 && b<d)
			return true;
		else return false;
	else return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	int r,c;
	while(t--)
	{
		scanf("%d%d",&r,&c);
		char arr[r][c+1];
		
		for(int i=0;i<r;i++)
		{
			scanf("%s",arr[i]);
		}
		
		
		
		queue<cell> bfs;
		bool status[r][c];
		int dist[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(arr[i][j]=='#')
					status[i][j]=true;
				else if(arr[i][j]=='.')
					status[i][j]=false;
				else
					status[i][j]=true;
				dist[i][j]=0;
			}
		}
		cell temp;
		//int dist[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				
				//temp.c = arr[i][j];
				temp.row = i;
				temp.col = j;
				//temp.dist = 0;
				
				if(arr[i][j]!='.' && arr[i][j]!='#')
				{
					bfs.push(temp);
				}
			}
		}
		int rowindex,colindex;
		cell temp2;
		while(!bfs.empty())
		{
			temp = bfs.front();
			rowindex = temp.row;
			colindex = temp.col;
			status[rowindex][colindex]=true;
			bfs.pop();
			
			if(arr[rowindex][colindex]!='*')
			{
				if(checkvalid(rowindex-1,colindex,r,c))
				{
					if(!status[rowindex-1][colindex])
					{
						temp2.row = rowindex-1;
						temp2.col = colindex;
						
						if(arr[rowindex-1][colindex]=='.')
						{
							arr[rowindex-1][colindex] = arr[rowindex][colindex];
							dist[rowindex-1][colindex] = dist[rowindex][colindex]+1;
							bfs.push(temp2);
						}
						else if(arr[rowindex-1][colindex]-'a'>=0 && arr[rowindex-1][colindex]!=arr[rowindex][colindex]  && dist[rowindex][colindex]<dist[rowindex-1][colindex])
						{
							arr[rowindex-1][colindex] = '*';
						}
					}
				}
				if(checkvalid(rowindex+1,colindex,r,c))
				{
					if(!status[rowindex+1][colindex])
					{
						temp2.row = rowindex+1;
						temp2.col = colindex;
						
						if(arr[rowindex+1][colindex]=='.')
						{
							arr[rowindex+1][colindex] = arr[rowindex][colindex];
							dist[rowindex+1][colindex] = dist[rowindex][colindex]+1;
							bfs.push(temp2);
						}
						else if(arr[rowindex+1][colindex]-'a'>=0 && arr[rowindex+1][colindex]!=arr[rowindex][colindex]  && dist[rowindex][colindex]<dist[rowindex+1][colindex])
						{
							arr[rowindex+1][colindex] = '*';
						}
					}
				}
				if(checkvalid(rowindex,colindex-1,r,c))
				{
					if(!status[rowindex][colindex-1])
					{
						temp2.row = rowindex;
						temp2.col = colindex-1;
						
						if(arr[rowindex][colindex-1]=='.')
						{
							arr[rowindex][colindex-1] = arr[rowindex][colindex];
							dist[rowindex][colindex-1] = dist[rowindex][colindex]+1;
							bfs.push(temp2);
						}
						else if(arr[rowindex][colindex-1]-'a'>=0 && arr[rowindex][colindex-1]!=arr[rowindex][colindex]  && dist[rowindex][colindex]<dist[rowindex][colindex-1])
						{
							arr[rowindex][colindex-1] = '*';
						}
							
					}
				}
				if(checkvalid(rowindex,colindex+1,r,c))
				{
					if(!status[rowindex][colindex+1])
					{
						temp2.row = rowindex;
						temp2.col = colindex+1;
						
						if(arr[rowindex][colindex+1]=='.')
						{
							arr[rowindex][colindex+1] = arr[rowindex][colindex];
							dist[rowindex][colindex+1] = dist[rowindex][colindex]+1;
							bfs.push(temp2);
						}
						else if(arr[rowindex][colindex+1]-'a'>=0 && arr[rowindex][colindex+1]!=arr[rowindex][colindex] && dist[rowindex][colindex]<dist[rowindex][colindex+1])
						{
							arr[rowindex][colindex+1] = '*';
						}
					}
				}
			}
		}
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				printf("%c",arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
