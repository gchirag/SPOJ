/*Breadth first Tree traversals*/
#include<stdio.h>
#include<stdlib.h>

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
	}

int height(struct node* node);
void breadthfirst (struct node* node);
void printlevel (struct node* node,int level);


int height(struct node* node){
	if (node==NULL)
	return 0;
	int lheight = height(node->left);
	int rheight = height(node->right);
	if(lheight>rheight)
	    return lheight+1;
	else return rheight+1;

}

void breadthfirst (struct node* node){
	int h = height(node);
	int i;
	for(i=1;i<=h;i++){
		printlevel(node,i);
	}
}

void printlevel (struct node* node,int level){
	if(node==NULL)
	    return;
	if(level==1)
	    printf("%d ",node->val);
	if(level>1)
	    {
		printlevel(node->left,level-1);
		printlevel(node->right,level-1);
	}
}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	root->left->right = newnode(5);
	root->right->left=newnode(6);
	breadthfirst(root);
system("PAUSE");
}



