#include <iostream>
#define mm 987654321
using namespace std;
int a[111],n,m,dp[111][222];
int main(void)
{
	cin >> n >> m;
	for(int e=0;e<m;e++) 
	{
		int k;
		cin >> k;
		a[k]=1;
	}
	for(int e=0;e<111;e++) for(int p=0;p<222;p++) dp[e][p]=mm;
	dp[0][0]=0;
	for(int e=0;e<=n;e++)
	{
		for(int p=0;p<222;p++)
		{
			if(dp[e][p]==mm) continue;
			if(a[e+1]) 
			{
				dp[e+1][p]=min(dp[e+1][p],dp[e][p]);
				continue;
			}
			dp[e+1][p]=min(dp[e+1][p],dp[e][p]+10000);
			dp[e+3][p+1]=min(dp[e+3][p+1],dp[e][p]+25000);
			dp[e+5][p+2]=min(dp[e+5][p+2],dp[e][p]+37000);
			if(p>=3) dp[e+1][p-3]=min(dp[e+1][p-3],dp[e][p]);
 		}
	}
	int mmm=mm;
	for(int p=0;p<222;p++) mmm=min(mmm,dp[n][p]);
	cout << mmm;
}
