#include <stdio.h>
#include <Vector>
#include <queue>
#include <string.h>
#define M 1001
using namespace std;
int n,m;
vector<int> arr[2222];
int flow[2222][2222],cap[2222][2222],dist[2222][2222];
int flows()
{
	vector<int> parent(2222,-1),vis(2222,987654321);
	queue<int> q;
	q.push(1);
	vis[1]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int e=0;e<arr[now].size();e++)
		{
			int next=arr[now][e];
			if(cap[now][next]-flow[now][next]>0&&vis[next]>vis[now]+dist[now][next])
			{
				vis[next]=vis[now]+dist[now][next];
				parent[next]=now;
				q.push(next);
			}
		}
	}
	int amount=987654321,ddd=0;
	for(int e=parent[n+M];e!=1;e=parent[e]) amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
	for(int e=parent[n+M];e!=1;e=parent[e])
	{
		ddd+=dist[parent[e]][e];
		flow[parent[e]][e]+=amount;
		flow[e][parent[e]]-=amount;
	}
	return ddd;
}
int main(void)
{
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int e=0;e<2222;e++) arr[e].clear();
		memset(flow,0,sizeof(flow));
		memset(cap,0,sizeof(cap));
		memset(dist,0,sizeof(dist));
		for(int e=0;e<m;e++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			arr[a+M].push_back(b);
			arr[b].push_back(a+M);
			cap[a+M][b]=1;
			dist[a+M][b]=c;
			dist[b][a+M]=-c;
		}
		for(int e=1;e<=n;e++)
		{
			arr[e].push_back(e+M);
			arr[e+M].push_back(e);
			if(e>1&&e<n)cap[e][e+M]=1;
			else cap[e][e+M]=2;
		}
		printf("%d\n",flows()+flows());
	}
}
