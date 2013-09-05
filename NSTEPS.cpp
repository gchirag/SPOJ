#include <iostream>
#include <stdio.h>
#include<stdlib.h>
int main(){
int n;
scanf("%d",&n);
int i,j,k;
for(i=0;i<n;i++){
	scanf("%d",&j);
	scanf("%d",&k);
	if(j==k)
		printf("%d\n",3*(k/2)+(k+1)/2);
	else if(j==k+2)
	    printf("%d\n",3*(k/2)+(k+1)/2+2);
	else printf("No Number\n");
}
system("PAUSE");
}
