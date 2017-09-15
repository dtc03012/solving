#include <iostream>
#include <string.h>
using namespace std;
int a[10001][10001],dp[10001];
string tmp;
int main(void)
{
	int n,l,k;
	cin >> n >> k >> l >> tmp;
	int r=tmp.size();
	for(int e=r-2;e>=0;e--)
	{
		for(int p=e+1;p<r;p++)
		{
			if(tmp[e]==tmp[p])
			{
				if(e+1>=p-1) a[e][p]=1;
				else a[e][p]=a[e+1][p-1]+1;
			}
		}
	}
	for(int e=0;e<r;e++) dp[e]=987654321;
	for(int e=1;e<r;e++)
	{
		if(k*(e+1)<=2*l*a[0][e])	dp[e]=1;
		for(int p=1;p<e;p++)
		{
			if(dp[p-1]!=987654321) if(k*(e-p+1)<=2*l*a[p][e]) dp[e]=min(dp[e],dp[p-1]+1);
		}
	}
	if(dp[r-1]==987654321) dp[r-1]=0;
	cout << dp[r-1];
}
