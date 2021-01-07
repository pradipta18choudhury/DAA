#include<stdio.h>
#include<math.h>
#include<limits.h>
typedef struct{
	int p,w;
	float rat;
}ks;
void bs(ks a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j].rat < a[j+1].rat){
				ks t = a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
	}
} 
int main(){
	ks it[7]= {{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
	for(int i=0;i<7;i++){
		it[i].rat = (float)((it[i].p)/it[i].w);
	}
	bs(it,7);
	// ks algo
	float solv[7]={0.0},optprofit = 0.0;
	int remwt = 15,i;
	for(int i=0;i<7;i++){
		if(it[i].w <= remwt){
			solv[i]=1.0;
			remwt=remwt-it[i].w;
		}
		else
			break;

	}
	printf("\n\n");
	if(i<7){
		solv[i]=(float)remwt/it[i].w;
	}
	printf("sol vec");
	for(int i=0;i<7;i++)printf("%f ",solv[i]);
	printf("\n\n");
	for (int i = 0; i < 7; ++i)
	{
		optprofit+=solv[i]*it[i].p;
	}
	printf("\n optimal max profit : %f",optprofit);
	return 0;
}