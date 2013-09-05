#include<cstdio>
#include<cstdlib>
#include <iostream>
#include<stdio.h>
using namespace std;

int ans[20];
int ansaux[20];
int main(){
	int t,n,i,current,max;
	char c;
	int prevlen;
	scanf("%d",&t);
	getchar();

	while(t--){
		c =  getchar();
	
        if(c=='\n'||c=='\r') {t=t+1; continue;
        }
        for(i=0;i<20;i++){
			ans[i]=0;
			ansaux[i]=0;
		}
		prevlen = -1;

		while(c!='\n'&&c!='\r'){
			
			while(c==' '||c=='\t') c = getchar();
			if(c=='\n'||c=='\r') break;

			current=1;
			c = getchar();
            
			while(c!=' '&&c!='\t'&&c!='\r'&&c!='\n'&&c!=EOF){
				
				current++;
				c = getchar();

			}
			if(prevlen == -1){
				prevlen = current;
				ansaux[prevlen]++;
			}
			else if(current==prevlen)
			    ansaux[prevlen]++;
			else if(current!=prevlen){
				if(ansaux[prevlen]>ans[prevlen])
				    ans[prevlen] = ansaux[prevlen];
				ansaux[prevlen]=0;
				prevlen = current;
				ansaux[prevlen]=1;
			}
			
			if(c=='\n'||c=='\r'||c==EOF) break;
			
			c = getchar();
  		}

		if(ansaux[prevlen]>ans[prevlen])
			    ans[prevlen] = ansaux[prevlen];
		ansaux[prevlen]=0;

  		
		max = 0;
		for(i=0;i<20;i++){
			if(ans[i]>max)
			    max = ans[i];
		}

		printf("%d\n",max);
		}

system("PAUSE");
return 0;

}
