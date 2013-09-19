#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

bool palin[2001][2001];

void display(int l)
{
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<l;j++)
		{
			printf("%s\t",(palin[i][j])? "true":"false");
		}
		printf("\n");
	}
}

void build_palin_aux(char* s,int len,int j,int k)
{
	while(j>=0&&k<len)
	{
		if(s[j]==s[k])
		{
			palin[j][k]=palin[j+1][k-1];
			palin[k][j]=palin[j+1][k-1];
		}
		else
		{
			palin[j][k]=false;
			palin[k][j]=false;
		}
		j--;
		k++;
	}

}


void build_palin(char* s,int len)
{

	int j,k;
	for(int i=0;i<len;i++)
	{
		palin[i][i]=true;
		j=i-1;
		k=i+1;

		if(s[k]==s[i])
		{
               	palin[i][k]=true;
               	palin[k][i]=true;
				j=i-1;
				k=i+2;
				build_palin_aux(s,len,j,k);
		}

		j=i-1;
		k=i+1;
		build_palin_aux(s,len,j,k);
		
	}
	//display(len);

}

void count_palin(char* s,int len)
{
	build_palin(s,len);
	int min;
	int number_of_palin[len];
	number_of_palin[0]=1;
	for(int i=1;i<len;i++)
	{
		min = number_of_palin[i-1]+1;
		
		for(int j=i-1;j>=0;j--)
		{
			if(palin[j][i])
			{
				if(j!=0)
					{
						if(number_of_palin[j-1]+1<min)
				    		min = number_of_palin[j-1]+1;
				    	}
				else
					min=1;
			}
		}
		number_of_palin[i]=min;
	}
	
//	for(int i=0;i<len;i++)
//	{
//		printf("%d\t",number_of_palin[i]);
//	}
//	printf("\n");

	printf("%d\n",number_of_palin[len-1]);

}

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	
	char c;
	char s[2001];
	
	while(t--)
	{

	 for(int i=0;i<2001;i++)
	{
		for(int j=0;j<2001;j++)
		{
			palin[i][j]=false;
		}
    }
        
 	int len=0;

	while((c=getchar())!='\n' && c!=EOF)
		s[len++]=c;

	s[len]='\0';
	
	count_palin(s,len);
	
    }
	//system("PAUSE");
	return 0;
}
