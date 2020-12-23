#include <stdio.h>
void main()
{
	int i,j,m,n;
	int a[10][10];
	int count=0;
	printf("\n enter order of matrix:");
	scanf("%d%d",&m,&n);
	printf("\n enter values of matrix:");
	   for(i=0;i<m;i++)
	   {
	   	  for(j=0;j<n;j++)
	   	  {
	   	  	scanf("%d",a[i][j]);
	   	  	if(a[i][j]==0)
	   	  	{
	   	  		count++;
	   	  	}
	   	  }
	   }
	printf("\n the entered matrix is:");
	   for(i=0;i<m;i++)
	   {
	   	  for(j=0;j<n;j++)
	   	  {
	   	  	 printf("%d",a[i][j]);
	   	  }
	   }
	if(count>m*n/2)
	{
		printf("\n the matric is a sparce matrix");
		printf("\n the no zeros present is %d",count);
	}
	else
	{
		printf("\n the matrix is not a sparce matrix");
		printf("\n the no. of zeros present is %d",count);
	}
}