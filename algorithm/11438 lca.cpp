#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int parent[111111][18],depth[111111],n,m,a,b;
vector<int> arr[111111];
void dfs(int n)
{
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e];
		if(depth[next]==-1)
		{
			depth[next]=depth[n]+1;
			parent[next][0]=n;
			dfs(next);
		}
	}
}
int main(void)
{
	memset(depth,-1,sizeof(depth));
	memset(parent,-1,sizeof(parent));
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++)
	{
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	depth[1]=0;
	dfs(1);
	for(int e=0;e<17;e++)
	{
		for(int p=2;p<=n;p++)
		{
			if(parent[p][e]!=-1)
			{
				parent[p][e+1]=parent[parent[p][e]][e];
			}
		}
	}
	scanf("%d",&m);
	for(int e=0;e<m;e++)
	{
		scanf("%d%d",&a,&b);
		if(depth[a]>depth[b])
		{
			int tmp=a;
			a=b;
			b=tmp;
		}
		int diff=depth[b]-depth[a];
		for(int p=0;diff;p++)
		{
			if(diff%2) b=parent[b][p];
			diff/=2;
		}
		if(b!=a)
		{
			for(int e=17;e>=0;e--)
			{
				if(parent[a][e]!=-1&&parent[a][e]!=parent[b][e])
				{
					b=parent[b][e];
					a=parent[a][e];
				}
			}
			a=parent[a][0];
		}
		printf("%d\n",a);
	}
}
