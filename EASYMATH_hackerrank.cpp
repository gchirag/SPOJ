#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,x,count2,count5,count10,r;
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        
        count2 = 0;
        count5 = 0;
        count10 = 0;
        
        while(x%10==0)
        {
        	count10++;
        	x=x/10;
        }

        while(x%2==0)
        {
        	count2++;
        	x=x/2;
        }

        while(x%5==0)
        {
        	count5++;
        	x=x/5;
        }
        
        r = 4%x;
        int no_fours = 1;
        int no_zeroes = count10+count5+((count2>2)? (count2-2):0 );
        
        while(r!=0)
        {
        	r = (r*10 +4)%x;
			no_fours++; 
        }
        

		printf("%d\n",2*no_fours+no_zeroes);

        

    }
    return 0;
}
