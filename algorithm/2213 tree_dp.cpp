#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,val[11111],dp[11111][2],vis[11111];
vector<int> arr[11111],arrr[11111],r;
int dfs(int now,int state)
{
	if(dp[now][state]) return dp[now][state];
	if(state)
	{
		int ret=val[now];
		for(int e=0;e<arrr[now].size();e++)
		{
			int next=arrr[now][e];
			ret+=dfs(next,0);
		}
		dp[now][state]=ret;
	}
	else
	{
		int ret=0;
		for(int e=0;e<arrr[now].size();e++)
		{
			int next=arrr[now][e];
			ret+=max(dfs(next,0),dfs(next,1));
		}
		dp[now][state]=ret;
	}
	return dp[now][state];
}
void push(int now,int state)
{
	if(state)
	{
		r.push_back(now);
		for(int e=0;e<arrr[now].size();e++)
		{
			int next=arrr[now][e];
			push(next,0);
		}
	}
	else
	{
		for(int e=0;e<arrr[now].size();e++)
		{
			int next=arrr[now][e];
			if(dp[next][1]>=dp[next][0]) push(next,1);
			else push(next,0);
		}
	}
}
void make(int now)
{
	vis[now]=1;
	for(int e=0;e<arr[now].size();e++){
		int next=arr[now][e];
		if(vis[next]==0)
		{
			arrr[now].push_back(next);
			make(next);
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&val[e]);
	for(int e=0;e<n-1;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	make(1);
	int f=dfs(1,0);
	int s=dfs(1,1);
	printf("%d\n",max(f,s));
	if(f>=s) push(1,0);
	else push(1,1);
	sort(r.begin(),r.end());
	for(int e=0;e<r.size();e++) printf("%d ",r[e]);
}
