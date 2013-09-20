#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n,m,copyn;
	scanf("%d",&n);
	scanf("%d",&m);

	char c[n][m];
	copyn=n;

	getchar();
	char* s =(char*) malloc(sizeof(char)*m);
	while(copyn)
	{

  		scanf("%s",s);
       	for(int i=0;i<m;i++)
		{
			c[n-copyn][i]=s[i];
		}

		copyn--;
	}

	int taken[n][m];

	for(int i=0;i<n;i++)
	    fill(taken[i],taken[i]+m,0);

	int number=0;
	int currenti,currentj;

	queue<int> helper;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			while(!helper.empty())
			    helper.pop();

			if(taken[i][j]==0)
			{
                bool done = false;
				currenti=i;
				currentj=j;
				number++;

				while(!done)
				{
					if(taken[currenti][currentj]==0)
					{
						helper.push(currenti*m+currentj);
	                    taken[currenti][currentj]=number;
						switch(c[currenti][currentj])
						{
							case 'S':
								currenti++;
								break;
							case 'N':
								currenti--;
								break;
							case 'E':
								currentj++;
								break;
							case 'W':
								currentj--;
								break;
						}
					}

					else if(taken[currenti][currentj]!=number && taken[currenti][currentj]!=0)
					{
						while(!helper.empty())
						{
							int p = helper.front();
							helper.pop();
							taken[p/m][p%m]=taken[currenti][currentj];
						}
						number--;
						done=true;
					}

					else done=true;
				}
			}

			else continue;
		}
	}
/*
	printf("\nRespective groupings are:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d\t",taken[i][j]);
		}
		printf("\n");
	}
	*/

	printf("%d",number);

	return 0;
	//system("PAUSE");
}
