#include<stdio.h>
#include<stdlib.h>

/*--------INPUTS are BINARY ONLY-----------*/
struct node{
int val;
struct node* next;
};

struct node * newnode(int data)
{
	struct node* node=(struct node*) malloc(sizeof(struct node));
	node->val=data;
	node->next=NULL;
	return node;
}

struct node* insert(struct node* head, int data)
{
	struct node* temp = newnode(data);
	temp->next= head ;
	head = temp;
	return head;
}

void display(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		printf("%d",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

struct node* addition(struct node* head1, struct node* head2)
{
	struct node* temp1=head1;
	struct node* temp2=head2;
	int carry=0;
	struct node* head3;
	struct node* temp;
	int value = temp1->val+temp2->val;

	head3= newnode(value%2);
	carry = value/2;
	temp = head3;

	temp1 = temp1->next;
	temp2 = temp2->next;
	
	while(!(temp1==NULL && temp2==NULL))
	{
		if(temp1==NULL)
		    value = temp2->val;
		else if(temp2==NULL)
		    value = temp1->val;
		else value = temp1->val+temp2->val;

		temp->next= newnode((value+carry)%2);
		carry = (value+carry)/2;
		temp = temp->next;
		
       	if(temp1!=NULL)
		   temp1 = temp1->next;
		if(temp2!=NULL)
			temp2 = temp2->next;

	}
	
	if(carry == 1)
		temp->next=newnode(1);

	return head3;
}

struct node* copy(struct node* head)
{
	struct node* temp = head;
	struct node* temp2;
	struct node* newhead = newnode(head->val);
	temp2 = newhead;
	temp=temp->next;
	while(temp!=NULL)
	{
		temp2->next=newnode(temp->val);
		temp = temp->next;
		temp2 = temp2->next;
	}
	
	return newhead;
}

struct node* reverse(struct node* head)
{
	struct node* temp = head;
	struct node* newhead;
	
	while(temp!=NULL)
	{
		newhead = insert(newhead,temp->val);
		temp=temp->next;
	}
	
	return newhead;
}

struct node* multiply(struct node* head1, struct node* head2)
{
	struct node* temp1;
	struct node* temp2 = head2;
	int count = 0;
	struct node* temp3 = newnode(0);
	
	while(temp2!=NULL)
	{
		if(temp2->val==1)
		{
			temp1 = copy(head1);
			
			for(int i=0; i<count; i++)
			{
				temp1=insert(temp1,0);
			}
			temp3 = addition(temp3,temp1);
		}
		
		temp2=temp2->next;
		count++;
	}
	
	return reverse(temp3);
}

int main(){

char c;
struct node* temp;

c = getchar();

struct node* head1 = newnode(c-'0');
c = getchar();
while(c!='\n')
{
	head1 = insert(head1,c-'0');
	c = getchar();
}

c = getchar();
struct node* head2 = newnode(c-'0');
c = getchar();
while(c!='\n')
{
	head2 = insert(head2,c-'0');
	c = getchar();
}

struct node* head3 = addition(head1,head2);

struct node* head4 = multiply(head1,head2);
display(head4);


system("PAUSE");
}
