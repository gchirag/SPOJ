#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int count;
int status[182][182];
//int flag;
struct listnode{
int a;
int b;
struct listnode* next;
}*rear,*front;                  //also creating front and rear pointers

struct listnode * newlistnode(int i,int j){           //pointers to tree nodes taken as input for list elements
	struct listnode* node=(struct listnode*) malloc(sizeof(struct listnode));
	node->a=i;
	node->b=j;
	node->next=NULL;
	return node;
}

void createlist(int i,int j){            //simply used for structural code
	//count=1;
	struct listnode* node=newlistnode(i,j);
	front = node;
	rear = front;
	return;
}

//Enqueueing at rear
void enqueue(int i,int j,int n,int m){
	//count++;
	if(i<0||j<0)
	    return;
	if(i>=n||j>=m)
	    return;
	    
	if(status[i][j]==0)
	    return;
	if(rear==NULL)
	rear = newlistnode(i,j);
	else{
	rear->next = newlistnode(i,j);
	rear=rear->next;
	}

	if(front==NULL)         //case when front = null before enqueue was called, it should also become same as rear
	    front = rear;

	return;
}

//Dequeue from front
int dequeue(int m){
	int i= front->a;
	int j= front->b;
	struct listnode* temp = front->next;
	free(front);
	front=temp;
	return i*m+j;
}


int main(){
	int t,n,m,i,j,k,l,x,y,r,s;
	scanf("%d",&t);
	char c;
	while(t--){
		scanf("%d",&n);
		scanf("%d",&m);

        int ans[n][m];
		int input;

		getchar();
//		flag=0;
		createlist(0,0);

    	for(r=0;r<n;r++){
			for(s=0;s<m;s++){
				status[r][s]=1;     //status 1 is unvisited
			}
		}

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				c=getchar();
				input=(int)c-48;
				ans[i][j]=n+m+1;

				if(input==1){
                    ans[i][j]=0;
					enqueue(i,j,n,m);
                    }
				}
			getchar();          //captures newline character
		}

			l=dequeue(m);
			count = 1;
			while(count<=n*m){
				k = dequeue(m);
				x = k/m;
				y = k%m;
				count++;
			//	printf("x:%d,y:%d,i:%d,j:%d,k:%d\n",x,y,i,j,k);
				//if(x>=n||y>=m) break;
				status[x][y]=0;
				

				if(x+1<n && ans[x][y]+1<ans[x+1][y]&& status[x+1][y]==1){
					//printf("x:%d,y:%d,i:%d,j:%d,k:%d\n",x,y,i,j,k);
				    ans[x+1][y] = ans[x][y]+1;
					enqueue(x+1,y,n,m);
					}
				if(y+1<m && ans[x][y]+1<ans[x][y+1]&& status[x][y+1]==1){
					//printf("x:%d,y:%d,i:%d,j:%d,k:%d\n",x,y,i,j,k);
				    ans[x][y+1] = ans[x][y]+1;
					enqueue(x,y+1,n,m);
					}
				if(x-1>=0 && ans[x][y]+1<ans[x-1][y]&& status[x-1][y]==1){
					//printf("x:%d,y:%d,i:%d,j:%d,k:%d\n",x,y,i,j,k);
				    ans[x-1][y] = ans[x][y]+1;
					enqueue(x-1,y,n,m);
					}
				if(y-1>=0 && ans[x][y]+1<ans[x][y-1]&& status[x][y-1]==1){
					//printf("x:%d,y:%d,i:%d,j:%d,k:%d\n",x,y,i,j,k);
				    ans[x][y-1] = ans[x][y]+1;
					enqueue(x,y-1,n,m);
					}
				
			}
	    
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
			printf("%d\t",ans[i][j]);
			}
			printf("\n");
		}
		
	//	printf("COUNT:%d\n",count);
	//free(ans);
	}
	system("PAUSE");
}




/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int status[182][182];

struct listnode{
int a;
int b;
struct listnode* next;
}*rear,*front;                  //also creating front and rear pointers

struct listnode * newlistnode(int i,int j){           //pointers to tree nodes taken as input for list elements
	struct listnode* node=(struct listnode*) malloc(sizeof(struct listnode));
	node->a=i;
	node->b=j;
	node->next=NULL;
	return node;
}

void createlist(int i,int j){            //simply used for structural code
	struct listnode* node=newlistnode(i,j);
	front = node;
	rear = front;
	return;
}

//Enqueueing at rear
void enqueue(int i,int j,int n,int m){
	if(i<0||j<0)
	    return;
	if(i>=n||j>=m)
	    return;
	if(status[i][j]==0)
	    return;

	if(rear==NULL)
	rear = newlistnode(i,j);
	else{
	rear->next = newlistnode(i,j);
	rear=rear->next;
	}
	
	if(front==NULL)         //case when front = null before enqueue was called, it should also become same as rear
	    front = rear;

	return;
}

//Dequeue from front
int dequeue(int m){
	int i= front->a;
	int j= front->b;
	struct listnode* temp = front->next;
	free(front);
	front=temp;
	return i*m+j;
}


int main(){
	int t,n,m,i,j,k,x,y,r,s;
	scanf("%d",&t);
	char c;
	while(t--){
		scanf("%d",&n);
		scanf("%d",&m);

        int ans[n][m];
		int input;

		getchar();

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				c=getchar();
				input=(int)c-48;
				ans[i][j]=n+m+1;

				if(input==1)
				    ans[i][j]=0;
			}
			getchar();          //captures newline character
		}

for(i=0;i<n;i++){
	for(j=0;j<m;j++){

		if(ans[i][j]!=0){

        	for(r=0;r<n;r++){
				for(s=0;s<m;s++){
					status[r][s]=1;     //status 1 is unvisited
				}
			}
			//printf("ANS[i][j] : %d\n",ans[i][j]);
			createlist(i,j);

			while(front!=NULL){
				k = dequeue(m);
				x = k/m;
				y = k%m;
				//printf("x:%d,y:%d,i:%d,j:%d,k:%d\n",x,y,i,j,k);

				status[x][y]=0;
			//	printf("INSIDE\n");
				if(ans[x][y]==0){
			//		printf("x:%d,y:%d,i:%d,j:%d,k:%d\n",x,y,i,j,k);
					ans[i][j] = abs(x-i)+abs(y-j);
					break;
					}

					enqueue(x+1,y,n,m);
					enqueue(x,y+1,n,m);
					enqueue(x-1,y,n,m);
					enqueue(x,y-1,n,m);
				}
				}
			}
			
		}

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
			printf("%d\t",ans[i][j]);
			}
			printf("\n");
		}
	//free(ans);
	}
	system("PAUSE");
}

*/
