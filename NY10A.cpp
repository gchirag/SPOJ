#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int t,n,i,bitarray[40],count[8];
	unsigned long long int j;
	char c;
	unsigned long long int value,temp;
	scanf("%d",&t);
	while(t--){
		
		scanf("%d",&n);
		getchar();
		for(i=0;i<40;i++){
			c = getchar();
			if(c=='T')
			    bitarray[i]=0;
			else bitarray[i]=1;
		}
		getchar();
		
		printf("%d ",n);

        value = 0;
		for(i=0;i<40;i++){
			//printf("%d",bitarray[i]);
			value = 2*value + bitarray[i];
		}
		//printf("\n%lld\n",value);
        temp = value;

		
		for(i=0;i<8;i++){
			count[i] = 0;
		}
		unsigned long long int x = 7;

		for(j=0;j<8;j++){
			value = temp;
			for(i=0;i<38;i++){
				if((value & x) == j)
				    {   count[j]++;
				    //printf("count[%d] is %d now\n",j,count[j]);

				    }
				value=value/2;
				}
			printf("%d ",count[j]);
			}
		
		printf("\n");

	}
}
