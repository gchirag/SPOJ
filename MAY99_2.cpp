#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

char get_manku_letter(int i)
{
	if(i==0) return 'm';
	else if(i==1) return 'a';
	else if(i==2) return 'n';
	else if(i==3) return 'k';
	else if(i==4) return 'u';
	
}

long long int power(long long int n, int k)
{
	long long int ans = 1;
	while(k>0)
	{
		if(k%2==1)
			ans = ans*n;
		n=n*n;
		k=k/2;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	long long int n;
	long long int ncopy;
	int digits;
	
	while(t--)
	{
		scanf("%lld",&n);
		ncopy=n;
		
		digits=0;
		int k=5;
		long long int rank;
		ncopy--;
		
		digits = log(4*ncopy+5)/log(5);
		
		//printf("%d\n",digits);
		
		long long int x = power(5,digits-1);
		//printf("%lld\n",x);
		rank = n - 5*(x-1)/4;
		//printf("%lld\n",rank);
		
		
		int digitcopy=digits;
		
		
		char* ans = (char*) malloc(sizeof(char)*(digits+1));
		
		rank=rank-1;
		
		while(digitcopy>0)
		{
			ans[digitcopy-1] = get_manku_letter(rank%5);
			rank =rank/5;
			digitcopy--;
		}
		
		ans[digits] = '\0';
		printf("%s\n",ans);
		
		free(ans);
		
	}
	return 0;
}
