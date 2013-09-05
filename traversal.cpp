/*Depth first Tree traversal*/
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
	};

void Postorder(struct node* node){
	if (node==NULL)
	return;
	Postorder(node->left);
	Postorder(node->right);
	printf("%d ",node->val);
}
void Preorder(struct node* node){
	if (node==NULL)
	return;
	printf("%d ",node->val);
	Preorder(node->left);
	Preorder(node->right);
}
void Inorder(struct node* node){
	if (node==NULL)
	return;
	Inorder(node->left);
	printf("%d ",node->val);
	Inorder(node->right);
}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	root->left->right = newnode(5);
	root->right->left=newnode(6);
	printf("\nPostorder\n");
	Postorder(root);
	printf("\nInorder\n");
	Inorder(root);
	printf("\nPreorder\n");
	Preorder(root);

system("PAUSE");
}



