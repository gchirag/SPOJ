#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

typedef struct Point{
	int x;
	int y;
}point; 

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
float distance(point p1, point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float normal(point* a, int n){
	float dist = 1000000;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(dist>distance(a[i],a[j]))
				dist = distance(a[i],a[j]);
		}
	}
	return dist;
}

float closestaux(point* a,int n){
	if(n<=3)
		return normal(a,n);
		
	float left = closestaux(a,n/2);
	float right = closestaux(a+n/2+1,n/2);
	
	
}


float closest(point* a, int n){
	qsort(a,n,sizeof(point),comparex);
	return closestaux(a,n);
}

int main(){
	point P[] = {{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
	int n = sizeof(P)/sizeof(P[0]);
	printf("%d\n",closest(P,n));
	return 0;
}
