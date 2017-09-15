#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <queue>
#define M 222
using namespace std;
int val[222],cap[444][444],level[444],work[444],flow[444][444],vis[444],n,m,ff,ss,f,s;
vector<int> arr[444],rr;
bool bfs()
{
	memset(level,-1,sizeof(level));
	level[f]=0;
	queue<int> q;
	q.push(f);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int e=0;e<arr[now].size();e++)
		{
			int next=arr[now][e];
			if(level[next]==-1&&cap[now][next]-flow[now][next]>0)
			{
				level[next]=level[now]+1;
				q.push(next);
			}
		}
	}
	if(level[s]==-1) return false;
	return true;
}
int dfs(int curr,int dest,int floww)
{
	if(curr==dest) return floww;
	for(int &e=work[curr];e<arr[curr].size();e++)
	{
		int next=arr[curr][e];
		if(level[next]==level[curr]+1&&cap[curr][next]-flow[curr][next]>0)
		{
			int df=dfs(next,dest,min(cap[curr][next]-flow[curr][next],floww));
			if(df>0)
			{
				flow[curr][next]+=df;
				flow[next][curr]-=df;
				return df;
			}
		}
	}
	return 0;
}
int main(void)
{
	scanf("%d%d%d%d",&n,&m,&ff,&ss);
	f=ff+M;
	s=ss;
	for(int e=1;e<=n;e++) scanf("%d",&val[e]);
	for(int e=0;e<m;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a+M].push_back(b);
		arr[b].push_back(a+M);
		arr[b+M].push_back(a);
		arr[a].push_back(b+M);
		cap[b+M][a]=987654321;
		cap[a+M][b]=987654321;
	}
	for(int e=1;e<=n;e++)
	{
		arr[e].push_back(e+M);
		arr[e+M].push_back(e);
		cap[e][e+M]=val[e];
	}
	int tot=0;
	while(bfs())
	{
		memset(work,0,sizeof(work));
		while(1)
		{
			int ff=dfs(f,s,987654321);
			if(ff==0) break;
			tot+=ff;
		}	
	}
	queue<int> q;
	q.push(f);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int e=0;e<arr[now].size();e++)
		{
			int next=arr[now][e];
			if(vis[next]==0&&cap[now][next]-flow[now][next]>0)
			{
				vis[next]=1;
				q.push(next);
			}
		}
	}
	for(int e=1;e<=n;e++)
	{
		if(vis[e]&&!vis[e+M]) printf("%d ",e);
	}
}
