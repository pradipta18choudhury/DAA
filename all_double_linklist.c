#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head;
void insert_double();
void double_display();
void double_reverse();
void delete_any_position();
void insert_any_position();



void main()
{
	int ch;
	while(1)
	{
		printf("\n 1.insert");
		printf("\n 2.display");
		printf("\n 3.reverse");
		printf("\n 4.delete any position");
		printf("\n 5.insert ay any position");
		printf("\n 6.exit");
		printf("\n enter your choise");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_double();
				break;
			case 2:
				double_display();
				break;
			case 3:
				double_reverse();
				break;
			case 4:
				delete_any_position();
				break;
			case 5:
				insert_any_position();
				break;
			case 6:
				exit(0);
				break;
		}
	}
}


void insert_double()
{
	int n,i;
	printf("\n enter no of nodes:");
	scanf("%d",&n);
	printf("\n enter node data:");
	for(i=0;i<n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&temp->data);
		temp->right=NULL;
		temp->left=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			struct node *p=head;
			while(p->right!=NULL)
			{
				p=p->right;
			}
			p->right=temp;
			temp->left=p;
		}
	}
}

void double_reverse()
{
	struct node *p=head;
	struct node *q;
	while(p->right!=NULL)
	{
		q=p->right;
		p->right=p->left;
		p->left=q;
		p=p->left;
	}
	q=p->left;
	p->left=NULL;
	p->right=q;
	head=p;
}

void double_display()
{
	struct node *temp=head;
	while(temp->right!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->right;
	}
	printf("%d-->",temp->data);
}


void delete_any_position()
{
	int pos,i=0;
	struct node *temp;
	struct node *p=head;
	struct node *q;
	printf("\n enter position:");
	scanf("%d",&pos);
	while(i<pos-1)
	{
		p=p->right;
		i++;
	}
	temp=p->right;
	p->right=temp->right;
	q=temp->right;
	q->left=p;
}

void insert_any_position()
{
	struct node *p=head;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *q;
	int pos,i=0;
	printf("\n enter position:");
	scanf("%d",&pos);
	printf("\n enter node data:");
	scanf("%d",&temp->data);
	temp->right=NULL;
	temp->left=NULL;
	while(i<pos-1)
	{
		p=p->right;
		i++;
	}
	q=p->right;
	temp->left=p;
	temp->right=q;
	p->right=temp;
	q->left=temp;
}