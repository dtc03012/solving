#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
vector<int> arr[2222];
int cap[2222][2222],flow[2222][2222],d[2222][2222],dist[2222],parent[2222];
int main(void)
{
	int n,m[3];
	cin >> n >> m[1] >> m[2];
	while(n!=0&&m[1]!=0&&m[2]!=0)
	{
	memset(cap,0,sizeof(cap));
	memset(flow,0,sizeof(flow));
	memset(d,0,sizeof(d));
	for(int e=0;e<2222;e++) arr[e].clear();
	for(int e=1;e<=2;e++)
	
	{
		arr[0].push_back(e);
		arr[e].push_back(0);
		cap[0][e]=m[e];
	}
	for(int e=3;e<3+n;e++)
	{ 
		int a,b,c;
		cin >> a >> b >> c;
		arr[1].push_back(e);
		arr[2].push_back(e);
		arr[e].push_back(1);
		arr[e].push_back(2);
		cap[1][e]=987654321;
		cap[2][e]=987654321;
		cap[e][3+n]=a;
		d[1][e]=b;
		d[e][1]=-b;
		d[2][e]=c;
		d[e][2]=-c;
		arr[e].push_back(e+n);
		arr[e+n].push_back(e);
	}
	for(int e=3;e<3+n;e++)
	{
		arr[e].push_back(3+n);
		arr[3+n].push_back(e);
	}
	int tot=0;
	while(1)
	{
		for(int e=0;e<2222;e++)
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
		if(parent[3+n]==-1) break;
		int amount=987654321;
		for(int e=3+n;e!=0;e=parent[e]) amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
		for(int e=3+n;e!=0;e=parent[e])
		{
			tot+=amount*d[parent[e]][e];
			flow[parent[e]][e]+=amount;
			flow[e][parent[e]]-=amount;
		}
	}
	cout << tot << "\n";
	cin >> n >> m[1] >> m[2];
	}
}
