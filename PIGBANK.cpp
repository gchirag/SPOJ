#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int i,j,n,f,e,t;
	scanf("%d",&n);
	int infinity = 100000000;
	
	while(n--){
		scanf("%d",&f);
		scanf("%d",&e);
		int ans[e-f+1];
        scanf("%d",&t);
        int val[t];
        int weight[t];
        
        for(i=0;i<t;i++){
			scanf("%d",&val[i]);
            scanf("%d",&weight[i]);
         }
         
         ans[0]=0;
         
         for(i=1;i<e-f+1;i++){
				ans[i]=infinity;
				for(j=0;j<t;j++){
					if(i-weight[j]>=0)
						if(ans[i]>ans[i-weight[j]]+val[j]){
							ans[i]=ans[i-weight[j]]+val[j];
						}
				}
        }
        if(ans[e-f]!=infinity)
		printf("The minimum amount of money in the piggy-bank is %d.\n",ans[e-f]);
		else printf("This is impossible.\n");

	}

	system("PAUSE");
	    
}
