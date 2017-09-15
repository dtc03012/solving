#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> arr[111];
int cap[111][111],flow[111][111],n,m;
bool tmr(int a,int b)
{
	return a<b;
}
int main(void)
{
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++)
	{
		int k;
		scanf("%d",&k);
		arr[0].push_back(e);
		arr[e].push_back(0);
		cap[0][e]=k;
	}
	for(int e=n+1;e<=n+m;e++)
	{
		int k;
		scanf("%d",&k);
		arr[e].push_back(n+m+1);
		arr[n+m+1].push_back(e);
		cap[e][n+m+1]=k;
	}
	for(int e=1;e<=n;e++)
	{
		for(int p=n+1;p<=n+m;p++)
		{
			arr[e].push_back(p);
			arr[p].push_back(e);
			cap[e][p]=1;
		}
	}
	for(int e=1;e<=n;e++) sort(arr[e].begin(),arr[e].end(),tmr);
	while(1)
	{
		vector<int> parent(111,-1);
		queue<int> q;
		q.push(0);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			for(int e=0;e<arr[now].size();e++)
			{
				int next=arr[now][e];
				if(cap[now][next]-flow[now][next]>0&&parent[next]==-1)
				{
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
			flow[parent[e]][e]+=amount;
			flow[e][parent[e]]-=amount;
		}
	}
	int pp=0;
	for(int e=1;e<=n;e++)
	{
		if(cap[0][e]!=flow[0][e]) pp++; 
	}
	for(int e=n+1;e<n+m+1;e++)
	{
		if(cap[e][n+m+1]!=flow[e][n+m+1]) pp++;
	}
	if(pp)
	{
		printf("-1");
		return 0;
	}
	for(int e=1;e<=n;e++)
	{
		for(int p=n+1;p<n+m+1;p++)
		{
			printf("%d",flow[e][p]);
		}	
		printf("\n");
	}	
}
