/****
Write a C Program that reads two sequence of characters or two strings as
input and find the longest common subsequence among two strings as output
using Dynamic Programming.The followings things must come as output.
****/

#include <stdio.h>
#include <limits.h>
#include <string.h>

int max(int a,int b)
{
	return (a>b);
}

int helper(char *s1,char *s2,int m,int n,int dp[m+1][n+1])
{
	int ans=0;
	if(m==0 || n==0)
		return 0;

	if(dp[m][n]>-1)
		return dp[m][n];

	if(s1[0]==s2[0])
		return 1+helper(s1+1,s2+1,m-1,n-1,dp);

	else
	{
		int option1=helper(s1,s2+1,m,n-1,dp);
		int option2=helper(s1+1,s2,m-1,n,dp);
		ans=max(option1,option2);
	}

	dp[m][n]=ans;
	return ans;

}

int lcs(char *arr,char *brr)
{
	int ans=0;
	int m=strlen(arr);
	int n=strlen(brr);

	int dp[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
			dp[i][j]=-1;
	}

	ans=helper(arr,brr,m,n,dp);

	return ans;
}

int main()
{
	char arr[]="ABA";
	char brr[]="AAA";

	printf("%d\t",lcs(arr,brr));
	return 0;
}