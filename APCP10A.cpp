#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int a1,a2,a3;
	scanf("%d %d %d",&a1,&a2,&a3);
	while(!(a1==0&&a2==0&&a3==0)){
		if(a1-a2==a2-a3)
		    printf("AP %d\n",a3+a3-a2);
		else printf("GP %d\n",a3*(a3/a2));

		scanf("%d %d %d",&a1,&a2,&a3);
	}
return 0;
//system("PAUSE");
}
