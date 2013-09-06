#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef struct Point{
	int x;
	int y;
	int index;
}point; 

typedef struct Bestpoints{
	int x1;
	int x2;
	int y1;
	int y2;
	int index1;
	int index2;
	double min;
	
}bestpoints;

bestpoints Best;

int comparex(const void* a,const void* b){
	point* m =(point*) a;
	point* n =(point*) b;
	return m->x-n->x;
}

int comparey(const void* a,const void* b){
	point* m =(point*) a;
	point* n =(point*) b;
	return m->y-n->y;
}

double distance(point p1, point p2){
	return sqrt(((double)(p1.x-p2.x))*((double)(p1.x-p2.x))+((double)(p1.y-p2.y))*((double)(p1.y-p2.y)));
}

bestpoints normal(point* a, int n){
	//double dist = 100000000000;
	bestpoints b;
	b.min = 10000000;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(b.min>distance(a[i],a[j]))
			{
                b.min = distance(a[i],a[j]);
                b.x1 = a[i].x;
                b.x2 = a[j].x;
                b.y1 = a[i].y;
                b.y2 = a[j].y;
                b.index1=a[i].index;
                b.index2=a[j].index;
			}
				
		}
	}
	return b;
}

bestpoints stripclosest(point* a, int n, bestpoints b)
{
	qsort(a,n,sizeof(point),comparey);
	
	
	for(int i=0;i<n;i++)
	{
		for(int j = i+1;j<n&&j<i+8;j++)
		{
			if(distance(a[i],a[j])<b.min)
			{
		      b.min = distance(a[i],a[j]);
                b.x1 = a[i].x;
                b.x2 = a[j].x;
                b.y1 = a[i].y;
                b.y2 = a[j].y;

                b.index1=a[i].index;
                b.index2=a[j].index;
			}
		}
	}
	
	return b;
}

bestpoints closestaux(point* a,int n){
	if(n<=3)
		return normal(a,n);
		
	bestpoints left = closestaux(a,n/2);
	bestpoints right = closestaux(a+n/2,n-n/2);

	bestpoints d = (left.min>right.min)? right:left;
	
	point strip[n];
	int j = 0;
	for(int i=0;i<n;i++)
	{
		if(abs(a[i].x - a[n/2].x) <= d.min )
		{
			strip[j++] = a[i];
		}
	}
	
	bestpoints f = stripclosest(strip,j,d);
	
	if(f.min<d.min)
	    return f;
	else
	    return d;
	
}


bestpoints closest(point* a, int n){
	qsort(a,n,sizeof(point),comparex);
	return closestaux(a,n);
}

int main(){

	int n;
	scanf("%d",&n);
	point P[n];

	for(int i=0;i<n;i++)
	{
        P[i].index = i;
		scanf("%d %d",&P[i].x,&P[i].y);

	}


	bestpoints p = closest(P,n);
	int index1=p.index1;
	int index2=p.index2;


	if(index1<index2)
		printf("%d %d %0.6lf\n",index1,index2,p.min );
	else
		printf("%d %d %0.6lf\n",index2,index1,p.min );

//printf("CLOSEST DISTANCE --- %0.6f    POINT1(%d,%d)   POINT2(%d,%d) INDICES %d %d \n",p.min,p.x1,p.y1,p.x2,p.y2,index1,index2 );

system("PAUSE");
	return 0;
}
