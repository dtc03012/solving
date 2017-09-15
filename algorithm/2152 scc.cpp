#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int n,m,curr,vis[111111],fin[111111],SN,sn[111111],degree[111111],val[111111],cal[111111],snn[111111],ss,t;
vector<vector<int> > scc;
vector<int> arr[111111],sarr[111111];
stack<int> s;
int dfs(int n)
{
	vis[n]=++curr;
	s.push(n);
	int result=vis[n];
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e];
		if(vis[next]==0) result=min(result,dfs(next));
		else if(fin[next]==0) result=min(result,vis[next]);
	}
	if(result==vis[n])
	{
		vector<int> kk;
		while(1)
		{
			int now=s.top();s.pop();
			kk.push_back(now);
			fin[now]=1;
			sn[now]=SN;
			if(now==n) break;
		}
		SN++;
		scc.push_back(kk);
	}
	return result;
}

int main(void)
{
	scanf("%d%d%d%d",&n,&m,&ss,&t);
	for(int e=0;e<m;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
	}
	for(int e=1;e<=n;e++)
	{
		if(vis[e]==0) dfs(e);
	}
	for(int e=1;e<=n;e++)
	{
		for(int p=0;p<arr[e].size();p++)
		{
			int next=arr[e][p];
			if(sn[e]!=sn[next]) 
			{
				degree[sn[next]]++;
				sarr[sn[e]].push_back(sn[next]);
			}
		}
	}
	for(int e=1;e<=n;e++) snn[sn[e]]++;
	queue<int> q;
	for(int e=1;e<=n;e++) if(e==ss) 
	{
		val[sn[e]]=snn[sn[e]];
		cal[sn[e]]=1;
	}
	for(int e=0;e<SN;e++)
	{
		if(degree[e]==0) q.push(e);
	}
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int e=0;e<sarr[now].size();e++)
		{
			int next=sarr[now][e];
			if(cal[now])
			{
				cal[next]=1;
				val[next]=max(val[next],val[now]+snn[next]);
			}
			degree[next]--;
			if(degree[next]==0) q.push(next);
		}
	}
	printf("%d\n",val[sn[t]]);
}
