#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
   	int n;
   	int done=0;
   	scanf("%d",&n);
	int* a = (int*)malloc(n*sizeof(int));
   	for(int k=0;k<n;k++)
           scanf("%d",&a[k]);
              
   	for(int j = n-1;j>0;j--)
           if(a[j]>a[j-1])
           {
            
            sort(a+j,a+n);
            int k = j;
            while(a[j-1]>=a[k])
					k++;
			int tmp = a[j-1];
            a[j-1]=a[k];
            a[k]=tmp;
            done = 1;
            break;      
           }
  
  	if(done)
		{
          for(int m=0;m<n;m++)
				printf("%d",a[m]);
		  printf("\n");	
		}
  	else
          printf("-1\n");        
	free(a);
  }

 return 0;
}

