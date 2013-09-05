#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int t,n,starter;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&starter);
		if(starter==0)
		    printf("Airborne wins.\n");
		else printf("Pagfloyd wins.\n");
	}
	system("PAUSE");
}
