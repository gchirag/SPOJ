#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	long long int n;
	scanf("%lld",&n);
	
	while(n!=1)
	{
		if(n%2==0)
		{
			n=n/2;
		}
		else
		{
			printf("NIE\n");
			//system("PAUSE");
			return 0;
		}
	}
	if(n==1)
	    printf("TAK\n");
	//system("PAUSE");
	return 0;
}
