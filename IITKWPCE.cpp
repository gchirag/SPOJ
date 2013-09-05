#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

int main(){
	string s;
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
	
	getline(cin,s);
	int l = s.length();
	string arr[l][l];
	
	for(int j=0;j<l;j++)
	{
		for(int i=0;i<l;i++)
		{
			if(i-j==0) arr[i][j]=1;
			else if(i-j==1||i-j==-1)
			    if(s[i]==s[j]) arr[i][j]=1;
			else if(s[i]==s[j])
			{
				arr[i][j]=arr[i+1][j-1];
			}
		}
	}
	
	
    }
	system("PAUSE");
	return 0;
}
