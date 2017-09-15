#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int> arr[111111];
int dp[111111][22],vis[111111],n;
void recur(int nn)
{
	vis[nn]=1;
	for(int e=0;e<arr[nn].size();e++)
	{
		int next=arr[nn][e];
		if(vis[next]==0)
		{
			recur(next);
			for(int p=1;p<=20;p++)
			{
				int rr=987654321;
				for(int q=1;q<=20;q++)
				{
					if(p==q) continue;
					rr=min(rr,dp[next][q]);
				}
				dp[nn][p]+=rr;
			}
		}
	}
	return;
}
int main(void)
{
	scanf("%d",&n);
	for(int e=0;e<n-1;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for(int e=1;e<=n;e++) for(int q=1;q<=20;q++) dp[e][q]=q;
	recur(1);
	int tot=987654321;
	for(int e=1;e<=20;e++) tot=min(tot,dp[1][e]);
	printf("%d",tot);
}
