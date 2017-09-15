#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define M 501
using namespace std;

vector<int> arr[1111];
int flow[1111][1111],cap[1111][1111],dist[1111][1111];

int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int e=0;e<1111;e++) arr[e].clear();
		memset(flow,0,sizeof(flow));
		memset(cap,0,sizeof(cap));
		memset(dist,0,sizeof(dist));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int p=1;p<=n;p++)
		{
			arr[p].push_back(p+M);
			arr[p+M].push_back(p);
			cap[p][p+M]=987654321;
		}
		for(int p=0;p<m;p++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			arr[a+M].push_back(b);
			arr[b].push_back(a+M);
			arr[a].push_back(b+M);
			arr[b+M].push_back(a);
			dist[b+M][a]=1;
			dist[a][b+M]=-1;
			cap[b+M][a]=987654321;
			dist[a+M][b]=1;
			dist[b][a+M]=-1;
			cap[a+M][b]=987654321;
		}
		for(int p=1;p<=n;p++)
		{
			int k;
			scanf("%d",&k);
			if(k==1)
			{ 
				arr[p+M].push_back(2*M);
				arr[2*M].push_back(p+M);
				cap[p+M][2*M]=1;
			}
		}
		for(int p=1;p<=n;p++) 
		{
			int k;
			scanf("%d",&k);
			if(k==1)
			{
				arr[0].push_back(p);
				arr[p].push_back(0);
				cap[0][p]=1;
			}
		}
		int tot=0;
		while(1)
		{
			vector<int> val(1111,987654321),parent(1111,-1);
			queue<int> q;
			q.push(0);
			val[0]=0;
			while(!q.empty())
			{
				int now=q.front();q.pop();
				for(int e=0;e<arr[now].size();e++)
				{
					int next=arr[now][e];
					if(cap[now][next]-flow[now][next]>0&&val[next]>val[now]+dist[now][next])
					{
						val[next]=val[now]+dist[now][next];
						parent[next]=now;
						q.push(next);
					}
				}
			}
			if(parent[2*M]==-1) break;
			int amount=987654321;
			for(int e=2*M;e!=0;e=parent[e]) amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
			for(int e=2*M;e!=0;e=parent[e])
			{
				tot+=dist[parent[e]][e];
				flow[parent[e]][e]+=amount;
				flow[e][parent[e]]-=amount;
			}
		}
		printf("%d\n",tot);
	}
}
