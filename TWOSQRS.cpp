#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

bool checksumsqr(long long int n)
{
	for(long long int i = 0, j = sqrt(n); i<=j ;)
	{	
	
		long long int k = i*i+j*j;
		if(k==n) return true;
		else if(k>n)
			j--;
		else i++;
	}
	return false;
}

int main()
{
	int t;
	long long int x;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&x);
		
		if(checksumsqr(x))
			printf("Yes\n");
		else 
			printf("No\n");
	}
	
	return 0;
}
