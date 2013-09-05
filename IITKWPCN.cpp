#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%*d");
		scanf("%d",&n);
		printf("%0.6f\n",(float)(n%2));
	}
	return 0;
}
