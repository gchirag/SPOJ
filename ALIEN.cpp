#include<cstdio>
#include<cstdlib>
#include<list>
using namespace std;
int main(){
    int t,stationno,maxpeople,i,j,temp,tempcount,tempans;
	scanf("%d",&t);
	int correctcount;
	int correctans;

	while(t--){
		scanf("%d",&stationno);
		scanf("%d",&maxpeople);
		//temp = 0;
		int ans[stationno];
		int people[stationno];
		int peoplecount[stationno];

		for(i=0;i<stationno;i++){
		scanf("%d",&people[i]);
		
			if(people[i]>maxpeople) {ans[i] = 0;peoplecount[i]=0;}
			else{
				ans[i] = 1;
				peoplecount[i] = people[i];
			}
		}
		
		temp=0;
		tempcount=0;
		tempans = 0;
		
		for(i=0;i<stationno;i++){
			if(tempcount+people[i]<=maxpeople){
				tempcount = tempcount+people[i];
				tempans = tempans+1;
			}
			else{
				ans[temp] = tempans;
				peoplecount[temp] = tempcount;
				tempcount = tempcount - people[temp];
				temp=temp+1;
				tempans = tempans - 1;
				i = i-1;
			}
			//if(i<stationno) i++;
		}
		ans[temp] = tempans;
		peoplecount[temp] = tempcount;
		for(i=temp+1;i<stationno;i++){
			ans[i] = ans[i-1]-1;
			peoplecount[i] = peoplecount[i-1]-people[i-1];
		}
		
		correctans=0;
		correctcount = 0;
		for(i=0;i<temp+1;i++){
			if((correctans<ans[i]||(correctans==ans[i]&&peoplecount[i]<correctcount))&&ans[i]<=stationno){
				correctcount = peoplecount[i];
				correctans = ans[i];
			}
		}
		printf("%d %d\n",correctcount,correctans);
	//	for(i=0;i<stationno;i++){
//			printf("---i: %d--ans: %d---peoplecount: %d----people: %d\n",i,ans[i],peoplecount[i],people[i]);
//		}
		
		
}
	system("PAUSE");
	return 0;
}
/*
struct station{
	int no;
	int val;
};


int main(){
	int t,stationno,maxpeople,i,j;
	scanf("%d",&t);
	
	struct station temp;
	temp.no=0;temp.val=0;
	//int inf = 10000000;
	int correctcount;
	int correctans;
	
	while(t--){
		scanf("%d",&stationno);
		scanf("%d",&maxpeople);
		int ans[stationno];
		int people[stationno];
		int peoplecount[stationno];
		int count;
		list<struct station> Bestlist[stationno];
		list<struct station>::iterator p;
		for(i=0;i<stationno;i++){
			scanf("%d",&people[i]);
			ans[i]=1;
			if(people[i]>maxpeople) ans[i] = 0;
			else{
				temp.no = 1;
				temp.val = people[i];
				Bestlist[i].push_back(temp);
				ans[i] = 1;
				peoplecount[i] = people[i];
			}
			
		}
		
		for(i=1;i<stationno;i++){
            for(p=Bestlist[i-1].begin();p!=Bestlist[i-1].end();++p){
				if((*p).val+people[i]<=maxpeople){
					temp.val = (*p).val+people[i];
					temp.no = (*p).no+1;
					Bestlist[i].push_back(temp);
					ans[i]=temp.no;
					peoplecount[i] = temp.val;
				}

			}

//			count = people[i];
//			if(count>maxpeople)
//				{peoplecount[i]=0;ans[i]=0;continue;}
//			for(j=i+1;j<stationno && count+people[j]<=maxpeople; j++){
//				count=count+people[j];
//			}
//			ans[i]=j-i;
//			peoplecount[i]=count;

   		}
		
		
		
//		for(i=0;i<stationno;i++){
//			if(ans[i]==0) continue;
//			if(i>=1){
//				if(peoplecount[i-1]+people[i]<=maxpeople){
//					ans[i]=ans[i-1]+1;
//					peoplecount[i]=peoplecount[i-1]+people[i];
//				}
//				else if(peoplecount[i-1]+people[i]>maxpeople){
//					if(people[i-1]+people[i]<=maxpeople){
//					ans[i]=2;
//					peoplecount[i]=people[i]+people[i-1];
//					}
//					else{
//						ans[i]=1;
//						peoplecount[i]=people[i];
//					}
//				}
//			}
//		}

		for(i=0;i<stationno;i++){
			//printf("---i: %d--ans: %d---peoplecount: %d----people: %d\n",i,ans[i],peoplecount[i],people[i]);
		}
		correctans=0;
		for(i=0;i<stationno;i++){
			if((correctans<ans[i]||(correctans==ans[i]&&peoplecount[i]<correctcount))&&ans[i]<=stationno){
				correctcount = peoplecount[i];
				correctans = ans[i];
			}
		}
		printf("%d %d\n",correctcount,correctans);

		for(i=0;i<stationno;i++){
			Bestlist[i].erase(Bestlist[i].begin(),Bestlist[i].end());
	}
		
	}
	
	
//system("PAUSE");
	return 0;
}
*/
