#include<cstdio>
#include<cstdlib>
using namespace std;

struct Node
{
	int data;
	Node* next;
};


Node* ReverseAlternate(Node* head)
{
	if(head==NULL)
		return head;
	Node* temp = head;
	Node* temp1 = head->next;
	Node* temp2 = head->next->next;
	Node* prevtemp1;
	head = temp1;
	
	while(1)
	{
		prevtemp1 = temp;
		temp1->next = temp;
		temp->next = temp2;
		temp = temp2;
		if(temp==NULL)
			break;
		temp1 = temp->next;
		temp2 = temp1->next;
		prevtemp1->next = temp1;
	}
	
	return head;
}

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));	
	Node* ele2 = (Node*)malloc(sizeof(Node));	
	Node* ele3 = (Node*)malloc(sizeof(Node));	
	Node* ele4 = (Node*)malloc(sizeof(Node));	
	head->data = 4;
	ele2->data = 3;
	ele3->data = 7;
	ele4->data = 2;
	head->next = ele2;
	ele2->next = ele3;
	ele3->next = ele4;
	ele4->next = NULL;

	Node* temp1 = head;
	while(temp1!=NULL)
	{
		printf("%d->",temp1->data);
		temp1=temp1->next;
	}
	printf("null\n");

	head = ReverseAlternate(head);
	
	Node* temp = head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("null\n");
	
}
