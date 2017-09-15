#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,curr,vis[111111],fin[111111],sn[111111],degree[111111],SM;
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
			sn[now]=SM;
			fin[now]=1;
			kk.push_back(now);
			if(now==n) break;
		}
		SM++;
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
		memset(vis,0,sizeof(vis));
		memset(fin,0,sizeof(fin));
		memset(sn,0,sizeof(sn));
		memset(degree,0,sizeof(degree));
		curr=0;
		SM=0;
		for(int e=0;e<111111;e++) arr[e].clear();
		scc.clear();
		scanf("%d%d",&n,&m);
		for(int e=0;e<m;e++){
			int a,b;
			scanf("%d%d",&a,&b);
		}
		for(int e=1;e<=n;e++) if(vis[e]==0) dfs(e);
		for(int e=1;e<=n;e++)
		{
			for(int p=0;p<arr[e].size();p++)
			{
				int next=arr[e][p];
				if(sn[e]!=sn[next]) degree[sn[next]]++;
			}
		}
		int tot=0,wh;
		for(int e=0;e<SM;e++) if(degree[e]==0) 
		{
			tot++;
			wh=e;
		}
		if(tot>1) printf("%dConfused\n",tot);
		else
		{
			sort(scc[wh].begin(),scc[wh].end());
			for(int e=0;e<scc[wh].size();e++) printf("%d ",scc[wh][e]);
			printf("\n");
		}
	}
}
