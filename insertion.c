#include <stdio.h>
int main()
{
	int n,a[10],key,j,i,k;
	printf("\n enter no of elements:");
	scanf("%d",&n);
	printf("\n enter array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n elements before sort:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

	
	for(j=1;j<n;j++)
	{
		key=a[j];
		k=j-1;
		while((k>=0)&&(a[k]>key))
		{
			a[k+1]=a[k];
			k=k-1;
			a[k+1]=key;
		}
	}
	printf("\n elements after sort:");
	for(k=0;k<n-1;k++)
	{
		printf("%d\t",a[k]);
	}
	printf("%d\t",a[k]);
	return (0);
}