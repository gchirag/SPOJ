#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int max_inner_index, max_outer_index, second_max_outer_index, max_inner_val, max_outer_val, second_max_outer_val;
	int t,n,inner,outer,ncopy;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		ncopy = n;
		
		max_inner_val = 0;
		max_outer_val = 0;
		second_max_outer_val = 0;
		max_inner_index = 1;
		max_outer_index = 1; 
		second_max_outer_index = 1;
		
		while(n--)
		{
			scanf("%d%d",&inner,&outer);
						
			if(inner>max_inner_val)
			{
				max_inner_val = inner;
				max_inner_index = ncopy-n;
			}
			
			if(outer>max_outer_val)
			{
				second_max_outer_index = max_outer_index;
				second_max_outer_val = max_outer_val;
				
				max_outer_val = outer;
				max_outer_index = ncopy-n;
			}
			else if(outer>second_max_outer_val)
			{
				second_max_outer_val = outer;
				second_max_outer_index = ncopy-n;
			}
		}

		if(max_inner_index==max_outer_index)
		{
			if(max_inner_val>second_max_outer_val)
				printf("%d\n",max_inner_index);
			else printf("-1\n");
		}
		else 
		{
			if(max_inner_val>max_outer_val)
				printf("%d\n",max_inner_index);
			else printf("-1\n");
		}
	}
	return 0;
}
