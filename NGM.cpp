#include <iostream>
#include <stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n%10==0)
	printf("2\n");
	else
	{
		printf("1\n");
		printf("%d\n",n%10);
	}
	system("PAUSE");
}
