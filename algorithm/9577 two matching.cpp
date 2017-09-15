#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int arr[222][222];
int a[222],b[222],vis[222];
bool dfs(int now)
{
	vis[now]=1;
	for(int e=0;e<111;e++)
	{
		if(arr[now][e])
		{
			int next=e;
			if(b[next]==-1||vis[b[next]]==0&&dfs(b[next]))
			{
				b[next]=now;
				a[now]=next;
				return true;
			}
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
		memset(arr,0,sizeof(arr));
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int e=0;e<m;e++)
		{
			int ft,st,k;
			scanf("%d%d%d",&ft,&st,&k);
			for(int p=0;p<k;p++)
			{
				int r;
				scanf("%d",&r);
				for(int q=ft;q<st;q++)
				{
					arr[r][q]=1;
				}
			}
		}
		int pp=0;
		for(int e=1;e<=n;e++)
		{
			memset(vis,0,sizeof(vis));
			if(!dfs(e)) pp++;
		}
		if(pp)
		{
			printf("-1\n");
			continue;
		}
		int ma=0;
		for(int e=1;e<=n;e++) ma=max(ma,a[e]);
		printf("%d\n",ma+1);
	}
}
