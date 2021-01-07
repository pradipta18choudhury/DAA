/***
Write a C Program that reads the frequency of characters in a
text as input and generates a huffman tree as output using
Greedy Approach. The program must produces following
things as output. a. The value and address of each internal node and each of its
child nodes. b. The leaf nodes of the huffman tree from left to right.
****/

#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node *left;
 int freq;
 struct node *right;
};

int occur[]={45,12,13,16,5,9};
int heapsize=sizeof(occur)/sizeof(occur[0]);

void min_heapify(int i)
{
  int left=2*i;
  int right=2*i+1;
  int smallest;
  if(left<=heapsize && occur[left]<occur[i])
   smallest=left;
  else
   smallest=i;
  if(right<=heapsize && occur[right]<occur[smallest])
   smallest=right;
  if(smallest!=i)
  {
   int temp=occur[smallest];
   occur[smallest]=occur[i];
   occur[i]=temp;
   min_heapify(smallest);
  }
}

int extract_min()
{
 int min=occur[0];
 occur[0]=occur[heapsize-1];
 heapsize--;
 min_heapify(0);
 return min;
}

void insert(int key)
{
 heapsize++;
 int i=heapsize-1,parent;
 occur[i]=key;
 if(i%2==0)
   parent=(i/2)-1;
  else
   parent=i/2;
 while(i>0 && occur[parent]>occur[i])
 {
  int temp=occur[parent];
  occur[parent]=occur[i];
  occur[i]=temp;
  i=parent;
  if(i%2==0)
   parent=(i/2)-1;
  else
   parent=i/2;
 }
}

void build_minheap()
{
  int i,n=heapsize;
  for(i=(n/2)-1;i>-1;i--)
  {
   min_heapify(i);
  }
}

int main()
{
 
 int j=0;
 build_minheap();
 for(int i=0;i<heapsize;i++)
  printf("%d ",occur[i]);
 printf("\n");
 int n=heapsize-1,k=0;
 while(k<n)
 {
  int min1=extract_min();
  int min2=extract_min();
  printf("%d %d\n",min1,min2);
  int sum=min1+min2;

  //create nodes for min1,min2 if not exist and also a node for sum
  //connect min1 and min2 to the left and right child of sum node respectively
  //check min1 and min2 exist or not
    
  insert(sum);
  for(int i=0;i<heapsize;i++)
   printf("%d ",occur[i]);
  printf("\n");
  k++;
 }
 //print all the leafnodes to check whether tree is correct
 
 return 0;
}