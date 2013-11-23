#include<cstdio>
#include<cstdlib>
using namespace std;

bool isred(long long int x,int year)
{
	if(year==0)
		return true;
	
	bool helper = isred(x/2,year-1);
	if(x%2==1)
		return helper;
	else 
		return !helper;	
}

int main()
{
int n;
long long int x;
scanf("%d",&n);
scanf("%lld",&x);

if(isred(x,n))
	printf("red\n");
else
	printf("blue\n");	
	
return 0;
}
