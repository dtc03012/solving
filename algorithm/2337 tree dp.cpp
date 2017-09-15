#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[155];
int dp[155][155],dp2[155],vis[155],n,m;
void recur(int now,int value)
{
	if(vis[now]) return;
	vis[now]=1;
	dp[now][1]=0;
	for(int e=0;e<arr[now].size();e++)
	{
		int next=arr[now][e];
		if(vis[next]) continue;
		recur(next,value+1);
		int mm[155];
		for(int p=1;p<=n;p++) mm[p]=dp[now][p];
		for(int p=1;p<=n;p++) if(dp[now][p]<987654321) dp[now][p]++;
		for(int p=1;p<=n;p++)
		{
			if(mm[p]<987654321)
			{
				int kk[155];
				for(int r=1;r<=n;r++) kk[r]=mm[r];
				for(int r=1;r<=n;r++) if(dp[next][r]<987654321) 
				{
					kk[r+p]=kk[p]+dp[next][r];
					dp[now][r+p]=min(dp[now][r+p],kk[r+p]);
				}
			}
		}
	}
	for(int e=1;e<=n;e++) dp2[e]=min(dp2[e],dp[now][e]+value);
}
int main(void)
{
	cin >> n >> m;
	for(int e=0;e<n-1;e++)
	{
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for(int e=0;e<155;e++) for(int p=0;p<155;p++) dp[e][p]=987654321;
	for(int e=0;e<155;e++) dp2[e]=987654321;
	recur(1,0);
	if(dp2[m]>=987654321) cout << "-1";
	else cout << dp2[m];
}
