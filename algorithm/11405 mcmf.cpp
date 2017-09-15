#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<int> arr[222];
int cap[222][222],flow[222][222],d[222][222],dist[222],parent[222];
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int e=1;e<=n;e++)
	{
		cin >> cap[0][e];
		arr[0].push_back(e);
		arr[e].push_back(0);
	}
	for(int e=n+1;e<n+m+1;e++) 
	{
		cin >> cap[e][n+m+1];
		arr[e].push_back(n+m+1);
		arr[n+m+1].push_back(e);
	}
	for(int e=n+1;e<n+m+1;e++)
	{
		for(int p=1;p<=n;p++)
		{
			cin >> d[p][e];
			arr[e].push_back(p);
			arr[p].push_back(e);
			cap[p][e]=987654321;
			d[e][p]=-d[p][e];
		}
	}
	int tot=0;
	while(1)
	{
		for(int e=0;e<222;e++)
		{
			parent[e]=-1;
			dist[e]=987654321;
		}
		queue<int> q;
		q.push(0);
		dist[0]=0;
		while(!q.empty())
		{
			int now=q.front();q.pop();
			for(int e=0;e<arr[now].size();e++)
			{
				int next=arr[now][e];
				if(cap[now][next]-flow[now][next]>0&&dist[next]>dist[now]+d[now][next])
				{
					dist[next]=dist[now]+d[now][next];
					parent[next]=now;
					q.push(next);
				}
			}
		}
		if(parent[n+m+1]==-1) break;
		int amount=987654321;
		for(int e=n+m+1;e!=0;e=parent[e]) amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
		for(int e=n+m+1;e!=0;e=parent[e])
		{
			tot+=amount*d[parent[e]][e];
			flow[parent[e]][e]+=amount;
			flow[e][parent[e]]-=amount;
		}
	}
	cout << tot;
}
