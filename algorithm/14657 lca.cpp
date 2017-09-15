#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
vector<pair<int,int> > arr[55555];
int kk[55555],vis[55555],gili,gap=987654321,wh=-1;
void dfs(int now,int tot,int mm)
{
	vis[now]=1;
	int pp=0;
	for(int e=0;e<arr[now].size();e++)
	{
		int next=arr[now][e].first;
		if(vis[next]==0)
		{
			pp++;
			dfs(next,tot+1,mm+arr[now][e].second);
		}
	}
	if(pp==0)
	{
		if(gili<tot)
		{
			gili=tot;
			gap=mm;
			wh=now;
		}
		if(gili==tot)
		{
			if(gap>mm)
			{
				gap=mm;
				wh=now;
			}
		}
	}
}
int main(void)
{
	int n,t;
	scanf("%d%d",&n,&t);
	for(int e=0;e<n-1;e++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr[a].push_back(make_pair(b,c));
		arr[b].push_back(make_pair(a,c));
		kk[a]++;
		kk[b]++;
	}
	for(int e=1;e<=n;e++)
	{
		if(kk[e]==1)
		{
			dfs(e,0,0);
			break;
		}
	}
	memset(vis,0,sizeof(vis));
	gili=0;
	gap=2e9;
	dfs(wh,0,0);
	printf("%d",(gap/t)+((gap%t)?1:0));
}
