#include<cstdio>
#include<cstdlib>
using namespace std;

int min(int a,int b)
{
	return (a<b)? a:b;
}
int main()
{
	int n;
	scanf("%d",&n);
	static short dptable[2][6101];
	char a[6101];
	getchar();	
	
	while(n--)
	{
	
		char c;
		int len =0;

		
		while((c=getchar())!='\n')
		{
			a[len++]=c;
		}
		
		//printf("%d\n%d\n",n,len);
		int i,j,gap;
		
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<len;j++)
			{
				dptable[i][j]=0;
			}
		}
		
/*			
		for(gap=1;gap<len;gap++)
		{
			for(i=0,j=gap;j<len;i++,j++)
			{
				//printf("i-%d,j-%d\n",i,j);
				table[i][j]= (a[i]==a[j])? table[i+1][j-1]:(min(table[i][j-1],table[i+1][j])+1);
			}
		}	
*/		
	for(gap=1;gap<len;gap++)
		{
			for(i=0,j=gap;j<len;i++,j++)
			{
				dptable[gap&1][i]= (a[i]==a[j])? dptable[(gap-2)&1][i+1]:(min(dptable[(gap-1)&1][i+1],dptable[(gap-1)&1][i])+1);
			}
		}

	printf("%u\n",dptable[(len-1)&1][0]);
		
	//	for(int i=0;i<len;i++)
//		{
//			for(int j=0;j<len;j++)
//			{
//				printf("%d\t",table[i][j]);
//			}
//			printf("\n");
//		}
//		
		
	//	int left=0,right=n-1;
	//	int middle = (left+right)/2;
	//	int count=0;
	//	while(!(left==middle && right==middle) && (left<n))
	//	{
	//		middle = (left+right)/2;
	//		if(a[left]==a[right])
	//		{
	//			left++;right--;
	//		}
	//		else
	//		{
	//			if(left==middle||right==middle)
	//			{
	//				count++;
	//				break;
	//			}
	//			else if(a[left+1]==a[right])
	//			{
	//				count++;
	//				left+=2;
	//				right--;
	//			}
	//			else if(a[right-1]==a[left])
	//			{
	//				count++;
	//				right-=2;
	//				left++;
	//			}
	//			else
	//			{
	//				count+=2;
	//				left++;
	//				right--;
	//			}
	//		}	
	//	}	
		
	//	printf("%d\n",count);
	
	}
	
	return 0;
}
