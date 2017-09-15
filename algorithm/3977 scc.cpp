#include <stdio.h>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int curr,SN,sn[111111],vis[111111],fin[111111],degree[111111],n,m;
vector<int> arr[111111];
vector<vector<int> > scc;
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
			sn[now]=SN;
			fin[now]=1;
			if(n==now) break;
		}
		SN++;
		scc.push_back(kk);
	}
	return result;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		curr=0;
		SN=0;
		memset(sn,0,sizeof(sn));
		memset(vis,0,sizeof(vis));
		memset(fin,0,sizeof(fin));
		memset(degree,0,sizeof(degree));
		for(int e=0;e<111111;e++) arr[e].clear();
		scc.clear();
		scanf("%d%d",&n,&m);
		for(int e=0;e<m;e++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			arr[a].push_back(b);
		}
		for(int e=0;e<n;e++)
		{
			if(vis[e]==0) dfs(e);
		}
		for(int e=0;e<n;e++)
		{
			for(int p=0;p<arr[e].size();p++)
			{
				int next=arr[e][p];
				if(sn[e]!=sn[next]) degree[sn[next]]++;
			}
		}
		int poss=0,wh;
		for(int e=0;e<SN;e++)
		{
			if(degree[e]==0) 
			{
				poss++;
				wh=e;
			}
		}
		if(poss>1) 
		{
			printf("Confused\n");
		}
		else
		{
			sort(scc[wh].begin(),scc[wh].end());
			for(int e=0;e<scc[wh].size();e++) cout << scc[wh][e] << "\n";
		}
		printf("\n");
	}
}
