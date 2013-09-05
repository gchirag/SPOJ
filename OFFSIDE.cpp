#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
int a,d;
scanf("%d",&a);
scanf("%d",&d);
int i;
int minattack,mindefend,mindefend2 = 10000;
while(!(a==0&&d==0)){
    minattack=10000;mindefend=10000;mindefend2 = 10000;
	int p,q;
	for(i=0;i<a;i++){
		scanf("%d",&p);
		if(p<minattack)
		    minattack = p;
	}
	
	for(i=0;i<d;i++){
		scanf("%d",&p);
		if(p<mindefend2)
		    if(p<mindefend){
				q = mindefend;
				mindefend = p;
				mindefend2 = q;
		    }
		    else{
				mindefend2 = p;
		    }
	}
	//printf("%d------%d----------%d-------\n",minattack,mindefend,mindefend2);
	if(minattack>=mindefend && minattack>=mindefend2)
	    printf("N\n");
	else printf("Y\n");
scanf("%d",&a);
scanf("%d",&d);
}
return 0;
//system("PAUSE");
}
