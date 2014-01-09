#include<cstdio>
#include<cstdlib>
using namespace std;
bool arr[1000001];
void build_arr(int k,int l)
{
	arr[1]=true;
	arr[k]=true;
	arr[l]=true;
	bool flag1,flag2,flag3;
	bool c1,c2,c3;
	for(int i=2;i<1000001;i++)
	{
		flag1 = false;
		flag2 = false;
		flag3 = false;
		
		if(i!=l && i!=k)
		{
			if(i-k>0)
			{
				flag1 = true;
				c1 = arr[i-k];
			}
			if(i-l>0)
			{
				flag2 = true;
				c2 = arr[i-l];
			}
			
			c3 = arr[i-1];
			
			if(!flag1 && !flag2)
			{
				arr[i]=!c3;
			}
			if(flag1 && !flag2)
			{
				arr[i] = (!c1)||(!c3);
			}
			if(!flag1 && flag2)
			{
				arr[i] = (!c2)||(!c3);				
			}
			if(flag1 && flag2)
			{
				arr[i] = (!c1)||(!c2)||(!c3);
			}
		}
	}	
}
int main()
{
	int k,l,m,p;
	scanf("%d%d%d",&k,&l,&m);
	
	build_arr(k,l);
	while(m--)
	{
		scanf("%d",&p);
		if(arr[p])
			printf("A");
		else
			printf("B");
	}
	return 0;
}
