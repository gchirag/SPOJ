// Standard Template Library example
#include<cstdio>
#include<cstdlib>
#include <iostream>
#include <list>
using namespace std;

// Simple example uses type int
struct party{
	int partyindex;
};

int main()
{
	int budget; int partyno;
	scanf("%d",&budget);
	scanf("%d",&partyno);
	int p,q,r,s;
	int maxfun;
	int minbudget;

	while(!(budget==0&&partyno==0)){

	list<struct party> BestList[budget+1];
    list<struct party>::iterator i;

	struct party temp;
	int flag;
	int partybudget[partyno];
	int partyfun[partyno];

	int ansfun[budget+1];

	for(p=0;p<partyno;p++){
		scanf("%d",&partybudget[p]);
		scanf("%d",&partyfun[p]);
		if(partybudget[p]>25||partybudget[p]<5||partyfun[p]<0||partyfun[p]>10)
		{
			partybudget[p]=0;
			partyfun[p]=0;
		}
	}
	ansfun[0]=0;

	for(p=1;p<budget+1;p++){
		ansfun[p]=0;
		for(q=0;q<partyno;q++){
			if(p-partybudget[q]>=0)
			    if(ansfun[p-partybudget[q]]+partyfun[q]>ansfun[p]){
					if(BestList[p-partybudget[q]].begin()==BestList[p-partybudget[q]].end()){
						temp.partyindex=q;
						BestList[p].erase(BestList[p].begin(),BestList[p].end());
						BestList[p].push_back(temp);
						ansfun[p]=ansfun[p-partybudget[q]]+partyfun[q];
					}
					else{
						flag=0;
                        for(i=BestList[p-partybudget[q]].begin();i!=BestList[p-partybudget[q]].end();++i){
							if((*i).partyindex==q)
							    flag=1;
                        }
						if(flag==0){
							temp.partyindex=q;
							ansfun[p]=ansfun[p-partybudget[q]]+partyfun[q];
							BestList[p].erase(BestList[p].begin(),BestList[p].end());
							BestList[p]=BestList[p-partybudget[q]];
							BestList[p].push_back(temp);
						}

					}
					}
		}
		//if(ansfun[p]<ansfun[p-1]) ansfun[p]=ansfun[p-1];

	}
	maxfun = 0;
	minbudget = 0;
	//minbudget = budget+1;
	for(p=0;p<budget+1;p++){
		if(ansfun[p]>maxfun){
			minbudget = p;
			maxfun = ansfun[p];
		}
	}

	printf("%d %d\n",minbudget,maxfun);


/*	for(p=1;p<budget+1;p++){
		printf("Most fun of a party of budget %d is %d\n",p,ansfun[p]);
		for(i=BestList[p].begin();i!=BestList[p].end();++i){
			printf("PARTY BUDGET = %d PARTY FUN = %d\t",partybudget[(*i).partyindex],partyfun[(*i).partyindex]);
		}
   	printf("\n\n");
	}
*/
	for(p=1;p<budget+1;p++){
		BestList[p].erase(BestList[p].begin(),BestList[p].end());
	}


	scanf("%d",&budget);
	scanf("%d",&partyno);

	}

	return 0;
   system("PAUSE");

}


