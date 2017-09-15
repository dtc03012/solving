#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define pl 401
using namespace std;
vector<int> arr[888];
int cap[888][888],flow[888][888],parent[888],n,m;

int main(void)
{
	cin >> n >> m;
	for(int e=1;e<=n;e++)
	{
		arr[e].push_back(e+pl);
		arr[e+pl].push_back(e);
		cap[e][e+pl]=1;
	}
	for(int e=0;e<m;e++)
	{
		int a,b;
		cin >> a >> b;
		arr[a+pl].push_back(b);
		arr[b].push_back(a+pl);
		arr[b+pl].push_back(a);
		arr[a].push_back(b+pl);
		cap[a+pl][b]=1;
		cap[b+pl][a]=1;
	}
	int tot=0;
	while(1)
	{
		memset(parent,-1,sizeof(parent));
		queue<int> q;
		q.push(1+pl);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			for(int e=0;e<arr[now].size();e++)
			{
				int next=arr[now][e];
				if(parent[next]==-1&&cap[now][next]-flow[now][next]>0)
				{
					parent[next]=now;
					q.push(next);
				}
			}
		}
		if(parent[2]==-1) break;
		int amount=987654321;
		for(int e=2;e!=1+pl;e=parent[e]) 
		{
			amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
		}
		for(int e=2;e!=1+pl;e=parent[e])
		{
			flow[parent[e]][e]+=amount;
			flow[e][parent[e]]-=amount;
		}
		tot+=amount;
	}
	cout << tot;
}


