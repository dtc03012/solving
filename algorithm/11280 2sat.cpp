#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int curr,SN,sn[21111],vis[21111],fin[21111],result[11111];
vector<vector<int> > scc;
vector<int> arr[21111];
stack<int> s;
pair<int,int> inf[22222];
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
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a=a<0?-2*(a+1):(a-1)*2+1;
		b=b<0?-2*(b+1):(b-1)*2+1;
		arr[opp(a)].push_back(b);
		arr[opp(b)].push_back(a);
	}
	for(int e=0;e<n*2;e++)
	{
		if(vis[e]==0) dfs(e);
	}
	for(int e=0;e<n;e++)
	{
		if(sn[2*e]==sn[2*e+1])
		{
			printf("0");
			return 0;
		}
	}
	printf("1\n");
	for(int e=0;e<2*n;e++) inf[e]=make_pair(sn[e],e);
	sort(inf,inf+2*n);
	memset(result,-1,sizeof(result));
	for(int e=2*n-1;e>=0;e--)
	{
		int now=inf[e].second;
		if(result[now/2]==-1) result[now/2]=!(now%2);
	}
	for(int e=0;e<n;e++) printf("%d ",result[e]);
}
