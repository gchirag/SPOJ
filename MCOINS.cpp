#include<cstdio>
#include<cstdlib>
using namespace std;
bool arr[1000001];

void build_arr(int k,int l)
{
	arr[1]=true;
	arr[k]=true;
	arr[l]=true;

	bool c1,c2,c3;

	for(int i=2;i<1000001;i++)
	{
		c1 = true;
		c2 = true;
		
		if(i!=l && i!=k)
		{
			if(i-k>0)
				c1 = arr[i-k];
			if(i-l>0)
				c2 = arr[i-l];
			c3 = arr[i-1];
			arr[i] = (!c1)||(!c2)||(!c3);
		}
	}	
}
int main()
{
	int k,l,m,p;
	scanf("%d%d%d",&k,&l,&m);
	//k=read_int();l=read_int();m=read_int();
	
	build_arr(k,l);
	while(m--)
	{
		scanf("%d",&p);
		//p=read_int();
		if(arr[p])
			printf("A");
		else
			printf("B");
	}
	return 0;
}
