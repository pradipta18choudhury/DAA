
/*****

Write a C Program for representing a given directed graph using adjacency
list representation. You are required to provide the following information
as output.
 a. Display the adjacency list as output.
 b. Display the out-degree of each vertex and total out-degree as output.
c. Display the in-degree of each vertex and total in-degree as output.
******/

#include<stdio.h>
#include<stdlib.h>
struct node
{
 int name;
 struct node *adj;
};

int main()
{
  struct node *adjarr[7];
  int i,inDegree[3]={0},outDegree[3]={0};
  char ch;
  for(i=1;i<4;i++)
  {
   printf("Enter the adjacent vertex of vertex %d:\n",i);
   struct node *new=(struct node *)malloc(sizeof(struct node));
   scanf("%d",&new->name);
   new->adj=NULL;
   adjarr[i]=new;
   printf("Do you want to continue(y/n):");
   scanf("\n%c",&ch);
   while(ch=='y')
   {
    struct node *new1=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&new1->name);
    new->adj=new1;
    new=new1;
    printf("Do you want to continue(y/n):");
    scanf("\n%c",&ch);
   }
  }
  //In Degree Calculation
  struct node *temp1;
  for(i=1;i<4;i++)
  {
  	temp1=adjarr[i];
  	inDegree[(temp1->name)-1]++;
  	while(temp1->adj!=NULL)
  	{
  		temp1=temp1->adj;
  		inDegree[(temp1->name)-1]++;
	}
  }
  //Out Degree Calculation
  struct node *temp2;
  for(i=1;i<4;i++)
  {
  	printf("%d",i);
  	temp2=adjarr[i];
  	outDegree[i-1]++;
  	while(temp2->adj!=NULL)
  	{
  		temp2=temp2->adj;
  		outDegree[i-1]++;
	}
  }
  //Printing all
  struct node *temp;
  for(i=1;i<4;i++)
  {
  	printf("%d",i);
  	temp=adjarr[i];
  	printf("-->%d",temp->name);
  	while(temp->adj!=NULL)
  	{
  		temp=temp->adj;
  		printf("-->%d",temp->name);
	}
	printf(" In Degree = %d, Out Degree = %d",inDegree[i-1],outDegree[i-1]);
	printf("\n");
  }
  return 0;
}