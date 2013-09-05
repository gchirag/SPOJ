#include<cstdio>
#include<cstdlib>
using namespace std;

void flip(int* arr, int n){
	int arrcpy[n+1];
	if(n!=0)
	{
		for(int i=0;i<=n;i++)
		{
		arrcpy[i]=arr[n-i];         //probably a -1 left
		}

		for(int i=0;i<=n;i++)
		{
			arr[i]=arrcpy[i];
		}
	}
}


void print(int* arr,int n){
    for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

bool pancakesort(int* arr, int n){
	int max = 0;
	if(n==0) return true;
	for(int i=1;i<n;i++){
		if(arr[i]>arr[max])
		    max = i;
	}
	//print(arr,n);
	//printf("MAXINDEX--%d\n",max);
	printf("AFTER FIRST FLIP--bringing max guy to top\n");
	flip(arr,max);
	print(arr,n);

	printf("AFTER MAIN FLIP--bringing max guy to bottom\n");
	flip(arr,n-1);
	print(arr,n);
	return pancakesort(arr,n-1);
	
}


int main(){
int a[6] = {3,5,4,2,1,9};
bool x = pancakesort(a,6);
printf("FINAL\n");
print(a,6);


system("PAUSE");

}

