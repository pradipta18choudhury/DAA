#include <stdio.h>
/***
Consider an arbritary string of certain length. Write a linear
time C program find number of substrings starting with X
and ending with Y where X and Y are any two characters
present in the string.
***/

int substr_count(char str[],char first,char second)
{
	int count=0,total=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]==first)
			count++;
		
		if(str[i]==second)
			total+=count;

	}
	return total;
}
int main()
{
	char str[100];
	printf("\n enter a string:");
	//for(int i=0;i<100;i++)
		scanf("\n%s",str);

	char start,end;
	printf("\n enter first character:");
	scanf("\n%c",&start);

	printf("\n enter second character:");
	scanf("\n%c",&end);

	printf("the count is %d",substr_count(str,start,end));
}