#include<stdio.h>
#include<math.h>
#include<limits.h>
int p[5] = {1,2,5,10,15};
int count[10001];
int am = 35;;
void makeChange(int am){
	int r = sizeof(p)/sizeof(int);
	for(int i=r-1;i>=0;i++){
		count[i]=(am/p[i]);
		am = am - (count[i]*p[i]);
	}
}
int power(int a, int b){
	int res = 1;
	while(b>0){
		if(b&1){
			res *= a;
		}
		a*=a;
		b>>=1;
	}
	return res;
}
int prem(int c){
	int i=0;
	int counter = 0;
	while(am > 0 ){
		am = am - power(c,i);
		counter++;
		i++;
	}
	return counter;
}
int main(){


	scanf("%d",&am);
	//makeChange(am);
	for(int i=1;i<=5;i++)printf("%d %d",i,count[i]);
	int x = prem(5);
	printf("\n%d",x);
	return 0;
}