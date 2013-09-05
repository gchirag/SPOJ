#include<cstdio>
#include<cstdlib>
#include <iostream>
using namespace std;

int ans[2001];
int main(){
	int t,n,i,current,a;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<2001;i++){
			ans[i]=0;
		}
		
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a);
			ans[a+1000]++;
		}
		current =0;
		for(i=0;i<2001;i++){
		    if(ans[i]>ans[current])
		        current = i;
		}
		if(ans[current]>n/2)
			printf("YES %d\n",current-1000);
		else printf("NO\n");
	}
	system("PAUSE");
	return 0;
}
