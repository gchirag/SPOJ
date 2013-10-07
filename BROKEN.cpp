#include<cstdio>
#include<cstdlib>
using namespace std;


int main()
{

	char input[1000002];
	int ans[1000002];

	int n;
	scanf("%d",&n);
	char c;
	int count[128];
	int counter;

	while(n!=0)
	{
		
		for(int i=0;i<128;i++)
		{
			count[i]=0;
		}
			
		getchar();
		int len=0;
		
		while((c=getchar())!='\n')
		{
			input[len]=c;
			ans[len++]=0;
		}
		
		input[len]='\0';
		
		
		counter=1;
		int start=0,end=0;
		
		//printf("Starting char------%c-----\n",input[start]);
		count[input[start]]++;
		
		while(end!=len)
		{
			if(counter>n)
			{
				ans[start]=end-1;
				//printf("updating character %c with length of string %d uptill character %c current counter %d start %d end %d\n",input[start],end-start,input[end],counter,start,end);
				//printf("count[start] %d\n",count[input[start]]);
				count[input[start]]--;
				//printf("count[start] %d\n",count[input[start]]);
				if(count[input[start]]==0)
					{
					counter--;
					//printf("Counter decrementing\n");
					}
				start++;
				//printf("Start increasing\n");
			}
			if(counter<=n)
			{
				//printf("End increasing\n");
				
				
				end++;
				if(end<len)
					{
						
						//printf("End changing from %c to %c Counter %d\n",input[end-1],input[end],counter);
						count[input[end]]++;
						if(count[input[end]]==1)
							{
							counter++;
							//printf("Counter incrementing\n");
							}
						
							
					}
				else break;	
			}
		}
		
		int maxdiff=-1;
		
		//if(start==0)
		//	maxdiff=end-start-1;
		
		if(counter<=n)
			maxdiff=end-start-1;
			
		for(int i=0;i<len;i++)
		{
			if(ans[i]-i>maxdiff)
				maxdiff=ans[i]-i;
			//printf("%d\t",ans[i]-i);
		}
				
		printf("%d\n",maxdiff+1);

		scanf("%d",&n);
	}
	return 0;
}
