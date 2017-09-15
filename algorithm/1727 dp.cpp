#include <iostream>
#include <algorithm>
using namespace std;
int a[1111],b[1111],dp[1111][1111],n,m,mm=987654321,vis[1111];
int abs(int n)
{
	return n>0?n:-n;
}
int main(void)
{
	for(int e=0;e<1111;e++) for(int p=0;p<1111;p++) dp[e][p]=987654321;
	cin >> n >> m;
	if(n<m)
	{
		for(int e=0;e<n;e++) cin >> a[e];
		for(int e=0;e<m;e++) cin >> b[e];
	}
	else
	{
		for(int e=0;e<n;e++) cin >> b[e];
		for(int e=0;e<m;e++) cin >> a[e];
	}
	if(n>m) swap(n,m);
	sort(a,a+n);
	sort(b,b+m);
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(e==0) dp[e][p]=abs(a[e]-b[p]);
			else
			{
				int mms=987654321;
				for(int q=0;q<p;q++) mms=min(mms,dp[e-1][q]);
				dp[e][p]=mms+abs(a[e]-b[p]);
			}
		}
	}
	for(int e=0;e<m;e++) mm=min(mm,dp[n-1][e]);
	cout << mm;
}
