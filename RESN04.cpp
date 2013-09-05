#include <iostream>
#include <stdio.h>
#include<stdlib.h>
int main(){
	int n,i,j,k,l;

	scanf("%d",&n);
	while(n--){
		l=0;
		scanf("%d",&j);
		for(i=1;i<=j;i++){
			scanf("%d",&k);
			l=l+k/i;
		}
		if(l%2!=0)
		    printf("ALICE\n");
		else printf("BOB\n");
	}

system("PAUSE");
}
