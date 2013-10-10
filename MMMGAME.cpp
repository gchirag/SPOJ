/*
Ans = Player1 if (XOR of piles !=0 && All_tiles_are_not_equal_to_1)
           or if (XOR of piles ==0 && All_tiles_are_equal_to_1)
    = Player2 otherwise
*/
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int t,n,x;
	int ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		bool x_equal_to_1 = true;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&x);
			if(x!=1)
				x_equal_to_1 = false;
			ans = ans^x;
		}
		
		if(x_equal_to_1)
		{
			if(ans==0)
				printf("John \n");
			else printf("Brother \n");
		}
		else
		{
			if(ans==0)
				printf("Brother \n");
			else printf("John \n");
		}
	}
	return 0;
}
