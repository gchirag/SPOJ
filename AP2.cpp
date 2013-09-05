#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
//printf("LIFE IS LIKE A BOX OF CHOCOLATES. YOU NEVER KNOW WHAT YOU'RE GONNA GET.\n");
int t,i;
scanf("%d",&t);
while(t--){
long long int a,b,sum,n,d,first;
scanf("%lld",&a);
scanf("%lld",&b);
scanf("%lld",&sum);
n = 2*sum/(a+b);
d = (b-a)/(n-5);
first = a-2*d;

printf("%d\n",n);

for(i=0;i<n;i++){
	printf("%d ",first+i*d);
}
	printf("\n");




}
return 0;
}
