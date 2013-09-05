
/*Breadth first Tree traversals using FIFO queue in O(n)*/
#include<stdio.h>
#include<stdlib.h>

//Tree node element - value and child pointers
struct node{
int val;
struct node* left;
struct node* right;
};

struct node * newnode(int data){
	struct node* node=(struct node*) malloc(sizeof(struct node));
	node->val=data;
	node->left=NULL;
	node->right=NULL;
	return node;
	};

//List element
struct listnode{
struct node* treenode;          //pointer to tree nodes stored in each list element
struct listnode* next;
}*rear,*front;                  //also creating front and rear pointers

struct listnode * newlistnode(struct node* tempnode){           //pointers to tree nodes taken as input for list elements
	struct listnode* node=(struct listnode*) malloc(sizeof(struct listnode));
	node->treenode=tempnode;
	node->next=NULL;
	return node;
}

void createlist(struct node* tempnode){            //simply used for structural code
	struct listnode* node=newlistnode(tempnode);
	front = node;
	rear = front;
	return;
}

//Enqueueing at rear
void enqueue(struct node* tempnode){
	if(tempnode==NULL)
		return;

	rear->next = newlistnode(tempnode);
	rear=rear->next;

	if(front==NULL)         //case when front = null before enqueue was called, it should also become same as rear
	    front = rear;

	return;
}

//Dequeue from front
struct node* dequeue(){
	struct node* tempnode = front->treenode;
	front=front->next;
	return tempnode;
}

void breadthfirst(struct node* root){

	if(root==NULL)
		return;
	createlist(root);

	struct node* temp;

	while(front!=NULL){             //Main algo--- whatever you take out.. put its children in at the end of the queue
		temp = dequeue();
		printf("%d ",temp->val);    //printing traversal
		enqueue(temp->left);
		enqueue(temp->right);
	}

 	if(front==NULL)
		printf("\nFinished\n");
}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	root->left->right = newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(9);
	breadthfirst(root);

system("PAUSE");
}





