#include <iostream>
#include <stdio.h>
#include<stdlib.h>

int main(){
	long long int i; float a,b; long long int j,k;
	for(i=0;i<10;i++){
		scanf("%f",&a);
		scanf("%f",&b);
		printf("a:%f\n",a);
		a=a/2;
		b=b/2;
		j=a+b;
		k=a-b;
		printf("%d\n%d\n",j,k);
	}
system("PAUSE");
}
