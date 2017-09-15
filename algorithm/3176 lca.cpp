#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int parent[111111][18],depth[111111],minn[111111][18],maxn[111111][18];
vector<pair<int,int> > arr[111111];
void dfs(int n)
{
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e].first,val=arr[n][e].second;
		if(depth[next]==-1)
		{
			depth[next]=depth[n]+1;
			parent[next][0]=n;
			minn[next][0]=val;
			maxn[next][0]=val;
			dfs(next);
		}
	}
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr[a].push_back(make_pair(b,c));
		arr[b].push_back(make_pair(a,c));
	}
	memset(parent,-1,sizeof(parent));
	memset(depth,-1,sizeof(depth));
	memset(maxn,-1,sizeof(maxn));
	memset(minn,-1,sizeof(minn));
	depth[1]=0;
	dfs(1);
	for(int e=0;e<17;e++)
	{
		for(int p=2;p<=n;p++)
		{
			if(parent[p][e]!=-1)
			{
				parent[p][e+1]=parent[parent[p][e]][e];
				minn[p][e+1]=min(minn[p][e],minn[parent[p][e]][e]);
				maxn[p][e+1]=max(maxn[p][e],maxn[parent[p][e]][e]);
			}
		}
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(depth[a]>depth[b])
		{
			int tmp=a;
			a=b;
			b=tmp;
		}
		int diff=depth[b]-depth[a],mins=987654321,maxs=-1;
		for(int p=0;diff;p++)
		{
			if(diff%2)
			{
				mins=min(mins,minn[b][p]);
				maxs=max(maxs,maxn[b][p]);
				b=parent[b][p];
			}
			diff/=2;
		}
		if(b!=a)
		{
			for(int e=17;e>=0;e--)
			{
				if(parent[a][e]!=-1&&parent[a][e]!=parent[b][e])
				{
					mins=min(mins,min(minn[b][e],minn[a][e]));
					maxs=max(maxs,max(maxn[b][e],maxn[a][e]));
					b=parent[b][e];
					a=parent[a][e];
				}
			}
			mins=min(mins,min(minn[a][0],minn[b][0]));
			maxs=max(maxs,max(maxn[a][0],maxn[b][0]));
		}
		printf("%d %d\n",mins,maxs);
	}
}
