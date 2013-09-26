#include<cstdio>
#include<cstdlib>
#include<list>
#include<cmath>
using namespace std;

int primefactors[100001][7];
int len[100001];
bool isprime[100001];

void display(int* arr, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void build_primefactors()
{
	fill(len,len+100001,0);
	fill(isprime,isprime+100001,true);
	for(int i=2;i<100001;i++)
	{
		if(isprime[i])
		{
			for(int k=i;k<100001;k+=i)
			{
				primefactors[k][len[k]] = i;
				isprime[k]=false; 
				len[k]++;
			}
		}
	}
	
	//for(int i=0;i<24;i++)
	//	display(primefactors[i],5);
		
}

int main()
{
	int t,n,m,temp,count,sum,product,kcopy;
	scanf("%d",&t);
	build_primefactors();
	//printf("%d\n",len[99999]);
	//display(primefactors[99999],5);
	
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		sum=m;
		int x = 1<<len[n];
		for(int k=1;k<x;k++)
		{
			kcopy=k;
			count=0;temp=0;
			product=1;
			while(k>0)
			{
				if(k%2==1)
				{
					product = product*primefactors[n][count];
					temp++;
				}
				count++;
				k=k/2;
			}
			
			//printf("Product is %d\n",product);
			if(temp%2==0)
				sum += (m/product);
			else sum -= (m/product);	
			k=kcopy;
		}
		printf("%d\n",sum);
	}
	return 0;
}
