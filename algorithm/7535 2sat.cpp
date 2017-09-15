#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
int curr,SN,sn[2222222],fin[2222222],vis[2222222];
vector<vector<int> > scc;
vector<int> arr[2222222];
stack<int> s;
int opp(int n)
{
	return n%2?n-1:n+1;
}
int dfs(int n)
{
	vis[n]=++curr;
	s.push(n);
	int result=vis[n];
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e];
		if(vis[next]==0) result=min(result,dfs(next));
		else if (fin[next]==0 ) result=min(result,vis[next]);
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
		scc.push_back(kk);
		SN++;
	}
	return result;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	for(int ee=1;ee<=t;ee++)
	{
		SN=0;
		curr=0;
		memset(vis,0,sizeof(vis));
		memset(fin,0,sizeof(fin));
		memset(sn,0,sizeof(sn));
		scc.clear();
		for(int e=0;e<2222222;e++) arr[e].clear();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int e=0;e<m;e++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=(a-1)*2+1;
			b=(b-1)*2+1;
			arr[opp(a)].push_back(b);
			arr[a].push_back(opp(b));
			arr[opp(b)].push_back(a);
			arr[b].push_back(opp(a));
		}
		for(int e=0;e<2*n;e++) if(vis[e]==0) dfs(e);
		int poss=0;
		for(int e=0;e<n;e++)
		{
			if(sn[2*e]==sn[2*e+1])
			{
				printf("Scenario #%d:\nSuspicious bugs found!\n",ee);
				poss++;
				break;
			}
		}
		if(poss==0)
		{
			printf("Scenario #%d:\nNo suspicious bugs found!\n",ee);
		}
		printf("\n");
	}
}
