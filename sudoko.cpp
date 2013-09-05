#include <cstdio>
#include <cstdlib>
using namespace std;

int isValid(int a[][9],int i,int j,int n)
{
	int count[9],p,q,r,s,t;

	for(r=0;r<9;r++){
		count[r]=0;
	}

	a[i][j]=n;

	for(p=0;p<9;p++){
		for(q=0;q<9;q++){
			if(a[p][q]==0) continue;
			count[a[p][q]-1]++;
			if(count[a[p][q]-1]>1)
			    return 0;
		}
		for(r=0;r<9;r++){
			count[r]=0;
		}
	}

	for(p=0;p<9;p++){
		for(q=0;q<9;q++){
			if(a[q][p]==0) continue;
			count[a[q][p]-1]++;
			if(count[a[q][p]-1]>1)
			    return 0;
		}
		for(r=0;r<9;r++){
			count[r]=0;
		}
	}

	for(p=0;p<9;p=p+3){
		for(q=0;q<9;q=q+3){

			for(t=0;t<9;t++){
				count[t]=0;
			}
			
			for(r=p;r<p+3;r++){
				for(s=q;s<q+3;s++){
					if(a[r][s]==0) continue;
					count[a[r][s]-1]++;

					if(count[a[r][s]-1]>1)
					    return 0;
				}
			}
		}
	}

	return 1;
}

bool Solve(int a[][9]){

int valid,p,q;
bool status;

for(p=0;p<9;p++){
	for(q=0;q<9;q++){
		if(a[p][q]==0){
			while(1){

				valid=isValid(a,p,q,a[p][q]+1);

				if(valid==1)
				{	status = Solve(a);
					if(status==false)
					    continue;
					if(status==true)
			    		return true;
				}
				
				if(valid==0 && a[p][q]>=9){
					a[p][q]=0;
					return false;
				}
			}
	}
}
}
return true;
}
		
void display(int a[][9]){
	int p,q;
	for(p=0;p<9;p++){
		for(q=0;q<9;q++){
			printf("%d ",a[p][q]);
		}
		printf("\n");
	}
}

int main()
{
	int p,q;
	int t;
	scanf("%d",&t);
    // 0 means unassigned cells
    int grid[9][9];/* = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    */
    while(t--){
    
    for(p=0;p<9;p++){                 //-------------TEST_CASE 2--------------------------
		for(q=0;q<9;q++){
			scanf("%d",&grid[p][q]);}
		}

    if (Solve(grid) == true){
	    display(grid);
    }
          
    else
         printf("No solution\n");
    }
//	system("PAUSE");
    return 0;
}
