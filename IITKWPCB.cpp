#include<cstdio>
#include<cstdlib>
#include<set>
#include<string>
#include<iostream>
using namespace std;

long long int gcd(long long int a,long long int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n;
		scanf("%lld",&n);
		bool found = false;
		
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		
		long long int k = n/2;
		while(k>0&&found==false)
		{
			if(gcd(n,k--)==1) found = true;
		}

		printf("%lld\n",k+1);
		
		
	}
	system("PAUSE");
	return 0;
	
}
