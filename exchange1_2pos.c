#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void exchange();
void insert();
void display();
int length();
void main()
{
	int len;
	insert();
	display();
	len=length();
	printf("\n %d nodes are present",len);
	exchange();
	printf("\n");
	display();
}
void insert()
{
	int n,i;
	printf("\n enter order of elements:");
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
void exchange()
{
	struct node *m;
	struct node *n;
	int i,j,k,temp;
	m=head;
	n=m->next;
	j=length();
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			k++;
			n=n->next;
		}
		temp=n->data;
		n->data=m->data;
		m->data=temp;
		m=m->next->next;
		n=m->next->next->next;
		i++;
		j--;

	}
}
int length()
{
	int count=0;
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	count++;
	return count;
}