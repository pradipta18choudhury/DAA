#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void insert();
void display();
void even_reverse();
void main()
{
	insert();
	display();
	even_reverse();
	display();

}
void insert()
{
	int n,i;
	printf("\n enter no of nodes:");
	scanf("%d",&n);
	printf("\n enter node data:");
	for(i=0;i<n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			struct node *p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=temp;
		}
	}
}
void display()
{
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("%d-->",temp->data);
}
void even_reverse()
{
	int temp;
	struct node *p=head;
	struct node *q=head;
	while((p->next!=NULL)&&(p->next->next!=NULL))
	{
		q=q->next->next;
		temp=q->data;
		q->data=p->data;
		p->data=temp;
	}
	p=p->next;
	display();
}