#include<cstdio>
#include<cstdlib>
#include <iostream>
using namespace std;

int main(){
	int t,n,r,i,min;
	unsigned long long ans;
	scanf("%d",&t);
	while(t--){
		ans = 1;
		scanf("%d",&n);
		scanf("%d",&r);
		r=r-1;n=n-1;
		//n=n-1;
		if(n==r){
			printf("1\n");
			continue;
		}
		min = r;
		if(n-r<min) min = n-r;
		
		for(i=1;i<=min;i++){
			ans = ans * (n-i+1) / i;
			//printf("ANS----%llu i ------ %d\n",ans,i);
		}

		printf("%llu\n",ans);
	}
	system("PAUSE");
	return 0;
}
