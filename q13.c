#include <stdio.h>
/****
Consider an array of elements given as input. Design a C
program that modifies the binary search technique in order
to search the position of a given key element in order of
log3n time complexity. Display the position of the key
element as outpu
****/

int ternary_search(int arr[],int left,int right,int key)
{
	while(left<=right)
	{
		int mid1=left+(right-left)/3;
		int mid2=right-(right-left)/3;

		if(arr[mid1]==key)
			return mid1;
		if(arr[mid2]==key)
			return mid2;

		if(key<arr[mid1])//left side
			return ternary_search(arr,left,mid1-1,key);

		else if(key>arr[mid2])//right side
			return ternary_search(arr,mid2+1,right,key);

		else//can b present in both left as well as right
			return ternary_search(arr,mid1-1,mid2+1,key);
	}
	return -1;
}

int main()
{
	int n;
	printf("\n enter no of elements:");
	scanf("%d",&n);

	int arr[n];
	printf("\n enter array elements:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int key;
	printf("\n enter key:");
	scanf("%d",&key);

	int p=ternary_search(arr,0,n,key);
	printf("the index of %d is %d",key,p);
	return 0;
}