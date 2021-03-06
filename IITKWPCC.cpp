#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

struct MyComparator
{
    const vector<int> & value_vector;

    MyComparator(const vector<int> & val_vec):
        value_vector(val_vec) {}

    bool operator()(int i1, int i2)
    {
        return value_vector[i1] < value_vector[i2];
    }
};

void print(const vector<int> & v, const char * msg)
{
    int size = v.size();

    for (int i = 0; i < size; ++i)
        printf("%d ",v[i]);

    printf("%s\n",msg);
}

bool check(int a,int b,const vector<int> &x,const vector<int> &y,const vector<int> &index,int n){
int i;
int k;
int start = 0;
int end = n-1;
int found =0;
while(start<=end&&found!=1){
	k=(start+end)/2;

	if(x[index[k]]==a){
		if(y[index[k]]==b)
			{
				found=1;
				return true;
			}
		else{
			for(i=k-1;i>=0;i--){
				if(x[index[i]]<a)   break;
				else if(y[index[i]]==b)
					{
						found = 1;
						return true;
					}
				}
			for(i=k+1;i<n;i++){
				if(x[index[i]]>a)  break;
				else if(y[index[i]]==b){
					found =1;
					return true;
				}
			}
			return false;
		}
	}
	else if(x[index[k]]<a){
		start = k+1;
	}
	else if(x[index[k]]>a){
		end = k-1;
	}
	
}
return false;
}


int counttriangles(const vector<int> &x,const vector<int> &y,const vector<int> &index,int n){
int i,j,diff;
int count = 0;
for(i=0;i<n;++i){
	for(j=i+1;j<n;++j){
		if (x[index[i]]==x[index[j]]){
			//printf("Point number i : %d, Point number j : %d\n",index[i],index[j]);
			
			diff = y[index[i]] - y[index[j]];
			//printf("Y Difference: %d\n",diff);
			
			if(check(x[index[i]]+diff,y[index[i]],x,y,index,n))     count ++ ;
			if(check(x[index[i]]-diff,y[index[i]],x,y,index,n))     count ++ ;
			if(check(x[index[i]]+diff,y[index[j]],x,y,index,n))     count ++ ;
			if(check(x[index[i]]-diff,y[index[j]],x,y,index,n))     count ++ ;
		}
		else break;

	}
}

return count;
}


int main()
{
	int n,i;
	scanf("%d",&n);
    vector<int> A(n), B(n), index(n);

    for (i = 0; i < n; ++i)
    {
        scanf("%d",&A[i]);
        scanf("%d",&B[i]);
        index[i] = i;
    }

	//print(A,"<=A");
	//print(B,"<=B");
	//print(index,"<=index");

    sort(index.begin(), index.end(), MyComparator(A));

	//print(A,"<=A");
	//print(B,"<=B");
	//print(index,"<=index");

	printf("%d",counttriangles(A,B,index,n));


 	//system("PAUSE");
    return 0;
}
