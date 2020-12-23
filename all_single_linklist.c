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
void single_reverse();
void delete_first();
void delete_any_position();
int length();
void insert_any_position();
void palindrome();
void duplicate1();
void even_pos_reverse();


void main()
{
	int ch,len;
	while(1)
	{
		printf("\n 1.insert");
		printf("\n 2.display");
		printf("\n 3.single linklist reverse");
		printf("\n 4.delete at first");
		printf("\n 5.length");
		printf("\n 6.delete any position");
		printf("\n 7.insert at any position");
		printf("\n 8.palindrome");
		printf("\n 9.duplicate");
		printf("\n 10.even position reverse:");
		printf("\n 11.EXIT");
		printf("\n enter your choise:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				single_reverse();
				break;
			case 4:
				delete_first();
				break;
			case 5:
				length();
				len=length();
				printf("%d nodes are present",len);
				break;
			case 6:
				delete_any_position();
				break;
			case 7:
				insert_any_position();
				break;
			case 8:
				palindrome();
				break;
			case 9:
				duplicate1();
				break;
			case 10:
				even_pos_reverse();
				break;
			case 11:
				exit(0);
				break;
		}
	}
}

void insert()
{
	int n,i;
	printf("\n enter number of nodes:");
	scanf("%d",&n);
	printf("enter node data:");
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
	printf("%d nodes are present",count);
}


void delete_first()
{
	struct node *temp=head;
	head=head->next;
	free (temp);
}

void single_reverse()
{
	struct node *p=head;
	struct node *q=head;
	int i=0,j=length()-1,k=0,temp;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->next;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		p=p->next;
		q=head;
		i++;j--;
	}
}

void delete_any_position()
{
	int pos,i=0;
	printf("\n enter position:");
	scanf("%d",&pos);
	struct node *p=head;
	struct node *q;
	while(i<pos-1)
	{
		p=p->next;
		i++;
	}
	q=p->next;
	p->next=q->next;
	free (q);
}

void insert_any_position()
{
	int i=0,pos;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *p=head;
	printf("\n enter position:");
	scanf("%d",&pos);
	printf("\n enter node data you want to insert:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	while(i<pos-1)
	{
		p=p->next;
		i++;
	}
	temp->next=p->next;
	p->next=temp;
}

void palindrome()
{
	struct node *p=head;
	struct node *q=head;
	int i=0,j=length()-1;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	while(i<j)
	{
		if(p->data==q->data)
		{
			p=p->next;
			q=head;
			i++;
			j--;
			//printf("\n palindrome");
		}
		else
			return;
		printf("\n palindrome");
	}
	printf("\n not palindrome");

}

void duplicate1()
{
	struct node * temp;
	struct node *p=head;
	struct node *q;
	while(p->next!=NULL)
	{
		q=p;
		while(q->next!=NULL)
		{
			if(p->data==q->next->data)
			{
				temp=q->next;
				q->next=q->next->next;
				free (temp);
			}
			else
				q=q->next;
		}
		p=p->next;
	}
}


void even_pos_reverse()
{
	struct node *p=head;
	struct node *q=head;
	int i=0,j=length()-1,k=0,temp;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->next;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		p=p->next->next;
		q=head;
		i+2;
		j-2;
	}
}