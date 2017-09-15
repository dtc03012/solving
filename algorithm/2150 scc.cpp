#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int n,m,curr,vis[555555],fin[555555],sn[555555],dist[555555],rest[555555],srest[555555],sdist[555555],SN,degree[555555],val[555555],cal[555555];
vector<int> arr









































































































































[555555];
vector<int> sarr[555555];
vector<vector<int> > scc;
stack<int> s;
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
			sn[now]=SN;
			fin[now]=1;
			kk.push_back(now);
			if(n==now) break;
		}
		SN++;
	}
	return result;
}
int main(void)
{
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
	}
	for(int e=1;e<=n;e++)
	{
		int a;
		scanf("%d",&a);
		dist[e]=a;
	}
	int start,k;
	scanf("%d%d",&start,&k);
	for(int e=0;e<k;e++)
	{
		int a;
		scanf("%d",&a);
		rest[a]=1;
	}
	for(int e=1;e<=n;e++)
	{
		if(vis[e]==0) dfs(e);
	}
	int sstart;
	for(int e=1;e<=n;e++)
	{
		int now=sn[e];
		sdist[now]+=dist[e];
		if(rest[e]) srest[now]=1;
		if(e==start) sstart=now;
		for(int p=0;p<arr[e].size();p++)
		{
			int next=arr[e][p];
			if(sn[e]==sn[next]) continue;
			sarr[sn[e]].push_back(sn[next]);
			degree[sn[next]]++;
		}
	}
	queue<int> q;
	cal[sstart]=1;
	for(int e=0;e<SN;e++)
	{
		val[e]=sdist[e];
		if(degree[e]==0) q.push(e);
	}
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int e=0;e<sarr[now].size();e++)
		{
			int next=sarr[now][e];
			if(cal[now])
			{
				cal[next]=1;
				val[next]=max(val[next],val[now]+sdist[next]);
			}
			degree[next]--;
			if(degree[next]==0) q.push(next);
		}
	}
	int result=0;
	for(int e=0;e<SN;e++) if(cal[e]&&srest[e]) result=max(result,val[e]);
	printf("%d",result);
}
