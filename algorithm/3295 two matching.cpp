#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[1111];
int a[1111],b[1111],vis[1111];
bool dfs(int now)
{
	vis[now]=1;
	for(int e=0;e<arr[now].size();e++)
	{
		int next=arr[now][e];
		if(b[next]==-1||vis[b[next]]==0&&dfs(b[next]))
		{
			b[next]=now;
			a[now]=next;
			return true;
		}
	}
	return false;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int e=0;e<1111;e++) arr[e].clear();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int e=0;e<m;e++)
		{
			int f,s;
			scanf("%d%d",&f,&s);
			arr[f].push_back(s);
		}
		int ttt=0;
		for(int e=0;e<n;e++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(e)) ttt++;
		}
		printf("%d\n",ttt);
	}
}
