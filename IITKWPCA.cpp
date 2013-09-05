#include<cstdio>
#include<cstdlib>
#include<set>
#include<string>
#include<iostream>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	set<string> abc;
	int i,prev;
	string a;
	string test;
	getchar();

	while(t--)
	{
		i=0;
 		getline(cin,a);
		a = a+" ";
		while(a[i]==' ') i++;
		prev = i;

		for(;i<(int)a.length();)
		{
			while(a[i]!=' ') i++;
			abc.insert(a.substr(prev,i-prev));
			while(a[i]==' ') i++;
			prev =i;
			
			
		}
		
		printf("%d\n",abc.size());
		abc.erase(abc.begin(),abc.end());
	}
	system("PAUSE");
	return 0;


}
