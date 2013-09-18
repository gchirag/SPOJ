#include<cstdio>
#include<cstdlib>
using namespace std;

void build_dearr(long long int* a,int n)
{
	long long int product=1;
	a[0]=0;
	a[1]=0;
	a[2]=1;
	a[3]=2;
	for(int i=4;i<n;i++)
	{
		a[i]=(i-1)*(a[i-1]+a[i-2])%1000000007;
	}

}

int main()
{
	int t;
	scanf("%d",&t);

	int arr[t];
	int max=0;

	for(int i=0;i<t;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>max)
		    max = arr[i];
	}
	
	long long int dearrangements[max+1];
	build_dearr(dearrangements,max+1);

    for(int i=0;i<t;i++)
	{
		printf("%lld\n",dearrangements[arr[i]]);
	}
	
	return 0;
}
