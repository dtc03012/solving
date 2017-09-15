#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int n,m,curr,SN,sn[333],vis[333],fin[333],degree[333],go[333],parent[333],rr[333][333][2],out[333];
vector<vector<int> > scc;
vector<int> arr[333],sarr[333];
stack<int> s;
vector<pair<int,int> > inf,inf2;
multiset<pair<int,int> > sset;
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
			fin[now]=1;
			kk.push_back(now);
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		curr=0;
		SN=0;
		memset(sn,0,sizeof(sn));
		memset(vis,0,sizeof(vis));
		memset(fin,0,sizeof(fin));
		memset(go,-1,sizeof(go));
		memset(parent,-1,sizeof(parent));
		memset(degree,0,sizeof(degree));
		memset(rr,0,sizeof(rr));
		memset(out,0,sizeof(out));
		scc.clear();
		inf.clear();
		inf2.clear();
		for(int e=0;e<333;e++) arr[e].clear();
		for(int e=0;e<333;e++) sarr[e].clear();
		int n;
		scanf("%d",&n);
		string tmp;
		for(int e=1;e<=n;e++)
		{
			cin >> tmp;
			for(int p=0;p<n;p++)
			{
				if(e==p+1) continue;
				if(tmp[p]=='1') arr[e].push_back(p+1);
			}
		}
		for(int e=1;e<=n;e++) if(vis[e]==0) dfs(e);
		int tot=0;
		for(int e=0;e<SN;e++)
		{
			if(scc[e].size()==1) continue;
			for(int p=0;p<scc[e].size()-1;p++) sset.insert(make_pair(scc[e][p],scc[e][p+1]));
			sset.insert(make_pair(scc[e][scc[e].size()-1],scc[e][0]));
		}
		for(int e=1;e<=n;e++)
		{
			for(int p=0;p<arr[e].size();p++)
			{
				int next=arr[e][p];
				if(sn[e]!=sn[next])
				{
					if(rr[sn[e]][sn[next]][0]==0)
					{
						rr[sn[e]][sn[next]][0]=e;
						rr[sn[e]][sn[next]][1]=next;
						sarr[sn[e]].push_back(sn[next]);
						sset.insert(make_pair(e,next));
						degree[sn[next]]++;
					}
				}
			}
		}
		queue<int> q;
		//for(int e=0;e<SN;e++) if(degree[e]==0)
	}
}
