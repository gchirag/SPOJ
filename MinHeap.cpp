#include<cstdio>
#include<cstdlib>
using namespace std;

int Heap[2000];
int len;

void swap(int i,int j)
{
	int temp = Heap[i];
	Heap[i]= Heap[j];
	Heap[j]= temp;
}

void insert(int n)
{
	Heap[len++]=n;
	int child = len-1;
	int parent = child/2;
	while(Heap[child]<Heap[parent] && child!=0)
	{
		swap(child,parent);
		child = parent;
		parent = parent/2;
	}
	
}

void deleter()
{
	swap(1,len-1);
	Heap[len-1]=0;
	len--;
	
	int parent = 1;
	int lchild;
	int rchild;
	bool done = false;
	lchild = 2*parent;
	rchild = 2*parent+1;
		
	while(!done)
	{
		if(rchild>=len)
		{
			if(lchild>=len)
					done=true;	
			else
			{
				if(Heap[parent] > Heap[lchild])
					swap(parent,lchild);		//done

				done = true;
			}
		}
		else
		{
			while(rchild<len && !(Heap[lchild]>=Heap[parent] && Heap[rchild]>=Heap[parent]))
			{
				if(Heap[lchild]<=Heap[rchild])
				{
					swap(lchild,parent);
					parent = lchild;
				}
				else
				{
					swap(rchild,parent);
					parent = rchild;
				}
				lchild = 2*parent;
				rchild = 2*parent+1;
			}
			
			if((Heap[lchild]>=Heap[parent] && Heap[rchild]>=Heap[parent]))
				done=true;
		}	
	}
}


int main()
{
	len=1;
	int t = 5000;
	int n;
	while(t--)
	{
		char c = getchar();
		if(c=='I')
		{
			scanf("%d",&n);
			insert(n);
		}
		else
		{
			deleter();
		}
		getchar();		
	}

	bool valid = true;
	int i;

	for(i=1;i<len/2;i++)
	{
		if(!(Heap[i]<=Heap[2*i] && Heap[i]<=Heap[2*i+1]))
			valid =false;
	}
	
	if(valid)
		printf("VALID bro\n");
	else printf("INVALID\n");
	
	return 0;
}
