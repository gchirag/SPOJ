#include <cstdio>
#include <cstdlib>
using namespace std;

int maximum(int a,int b,int c){
	if(a>=b&&a>=c)  return a;
	else if(b>=a&&b>=c) return b;
	else return c;
}

int main(){
	int t,n,m,i,j,max;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d",&m);
		
		int a[n][m];
		int d[n][m];
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
				if(i==0)
				    d[i][j]=a[i][j];
			}
		}
		
		for(i=1;i<n;i++){
			for(j=0;j<m;j++){
				if(j==0) d[i][j] = maximum(0,d[i-1][j],d[i-1][j+1])+a[i][j];
				else if(j==m-1) d[i][j] = maximum(d[i-1][j-1],d[i-1][j],0)+a[i][j];
				else d[i][j] = maximum(d[i-1][j-1],d[i-1][j],d[i-1][j+1])+a[i][j];
			}
		}
		
		i=n-1;
		max=0;
		for(j=0;j<m;j++){
			if(d[i][j]>max)
			    max = d[i][j];
		}
		printf("%d\n",max);
	}
	return 0;
}
