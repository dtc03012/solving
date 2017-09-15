#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;
long long int arr[111],n,s,tot,value[111][111],dp[111][111];
void recur(long long int a,long long int b,long long int rr,long long int rr2)
{
	if((a==1&&b==n)||(a==n&&b==1))
	{
		tot=min(tot,rr2);	
		return;
	}
	if(a<b)
	{
		if(b<n)
		{
			if(dp[a][b+1]>rr+rr2+arr[b])
			{
				dp[a][b+1]=rr+rr2+arr[b];
				recur(a,b+1,rr+arr[b],rr2+rr+arr[b]);	
			}
		}
		if(a>1)
		{
			long long int kk=value[a-1][b-1];
			if(dp[b][a-1]>rr2+rr+kk)
			{
				dp[b][a-1]=rr2+rr+kk;
				recur(b,a-1,rr+kk,rr2+rr+kk);
			}
		}
	}
	if(a>=b)
	{
		if(b>1)
		{
			if(dp[a][b-1]>rr+rr2+arr[b-1])
			{
				dp[a][b-1]=rr+rr2+arr[b-1];
				recur(a,b-1,rr+arr[b-1],rr2+rr+arr[b-1]);	
			}
		}
		if(a<n)
		{
			long long int kk=value[b][a];
			if(dp[b][a+1]>rr+rr2+kk)
			{
				dp[b][a+1]=rr+rr2+kk;
				recur(b,a+1,rr+kk,rr+rr2+kk);
			}
		}
	}
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		tot=1e18;
		scanf("%lld%lld",&n,&s);
		for(int e=0;e<111;e++) for(int p=0;p<111;p++) dp[e][p]=1e18;
		for(int e=1;e<n;e++)
		{
			scanf("%lld",&arr[e]);
			value[e][e]=arr[e];
		}
		for(int e=1;e<n;e++)
		{
			for(int p=e+1;p<n;p++) value[e][p]=value[e][p-1]+arr[p];
		}
		recur(s,s,0,0);
		printf("%lld\n",tot);
	}
}
