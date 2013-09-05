#include<cstdlib>
#include<cstdio>
using namespace std;

void insertsort(int * a, int n){
	int i,j,k,temp;
	for(i=1;i<n;i++){
		temp = a[i];
		for(j=i-1;j>=0;j--){

			if(a[j]>=temp){
				//printf("%dth position taken by %d\n",j+1,a[j]);
				a[j+1]=a[j];
				if(j==0)
					a[j]=temp;
			}
			else if((j!=i-1) && a[j]<temp){
                //printf("%dth ---2--- position taken by %d\n",j+1,temp);
				a[j+1] = temp;
				break;
			}
			else break;
		}
		//printf("TEMP--%d\n",temp);
		//printf("CURRENT ARRAY\n");
		//for(k=0;k<n;k++) printf("%d\t",a[k]);
		//	printf("\n");


		//a[j+1]=temp;
	}
	
}


int main(){
	int a[10]={3,9,8,7,6,3,4,3,2,1};
	int i;
	
	for(i=0;i<10;i++) printf("%d\t",a[i]);
	printf("\n");
	//system("PAUSE");
	insertsort(a,10);
	for(i=0;i<10;i++) printf("%d\t",a[i]);
	printf("\n");

	system("PAUSE");
	//return 0;
}
	
