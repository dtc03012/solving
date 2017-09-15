#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;
int SN,curr,vis[22222],fin[22222],sn[22222];
vector<vector<int> > scc;
vector<int> arr[22222];
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
		scc.push_back(kk);
		SN++;
	}
	return result;
}
int main(void)
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		SN=0;
		curr=0;
		memset(vis,0,sizeof(vis));
		memset(fin,0,sizeof(fin));
		memset(sn,0,sizeof(sn));
		scc.clear();
		for(int e=0;e<22222;e++) arr[e].clear();
		for(int e=0;e<m;e++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=a<0?-(a+1)*2:(a-1)*2+1;
			b=b<0?-(b+1)*2:(b-1)*2+1;
			arr[opp(a)].push_back(b);
			arr[opp(b)].push_back(a);
		}
		arr[opp(1)].push_back(1);
		for(int e=0;e<2*m;e++) if(vis[e]==0) dfs(e);
		int pp=0;
		for(int e=0;e<m;e++)
		{
			if(sn[2*e]==sn[2*e+1])
			{
				printf("no\n");
				pp++;
				break;
			}
		}
		if(pp==0)
		{
			printf("yes\n");
		}
	}
}
