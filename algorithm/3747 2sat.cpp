#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;
int curr,SN,sn[2222],vis[2222],fin[2222];
vector<vector<int> > scc;
vector<int> arr[2222];
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
			fin[now]=1;
			sn[now]=SN;
			kk.push_back(now);
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
		curr=0;
		SN=0;
		memset(vis,0,sizeof(vis));
		memset(sn,0,sizeof(sn));
		memset(fin,0,sizeof(fin));
		scc.clear();
		for(int e=0;e<2222;e++) arr[e].clear();
		for(int e=0;e<m;e++)
		{
			int a,b;
			cin >> a >> b;
			a=a<0?-(a+1)*2:(a-1)*2+1;
			b=b<0?-(b+1)*2:(b-1)*2+1;
			arr[opp(a)].push_back(b);
			arr[opp(b)].push_back(a);
		}
		for(int e=0;e<2*n;e++) if(vis[e]==0) dfs(e);
		int poss=0;
		for(int e=0;e<n;e++)
		{
			if(sn[2*e]==sn[2*e+1])
			{
				cout << "0\n";
				poss++;
				break;
			}
		}
		if(poss==0) cout << "1\n";
	}
}
