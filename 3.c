#include<stdio.h>
#include<math.h>
#include<limits.h>
typedef struct{
	int s;
	int e;
}av;
void bs(av a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j].e > a[j+1].e ){
				av t = a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
} 

int main(){
	av a[11]= {{3,5},{0,6},{5,9},{6,10},{1,4},{3,9},{5,7},{12,16},{2,14},{8,12},{8,11}};
	bs(a,11);
	av solv[11];
	int x =1;
	int c = 1;
	for(int i=2;i<=11;i++){
		if(a[i].s >= a[x].e){
			solv[c].s = a[i].s;
			solv[c].e = a[i].e;
			x=i;
			c++;
		}
	}
	for(int i=0;i<11;i++){
		printf("s: %d e: %d \n",a[i].s,a[i].e);
	}
	printf("\n\n%d\n",c);
	printf("s: %d e: %d\n",a[0].s,a[0].e );
	for(int i=1;i<c;i++){
		printf("s: %d e: %d \n",solv[i].s,solv[i].e);
	}
	
	return 0;
}