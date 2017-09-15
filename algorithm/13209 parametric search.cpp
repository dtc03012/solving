#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int> arr[111111],rr;
int val[111111],vis[111111],num=0;
long long int dfs(int now,long long int k)
{
	priority_queue<int> qq;
	long long int pp=val[now];
	vis[now]=1;
	for(int e=0;e<arr[now].size();e++)
	{
		int next=arr[now][e];
		if(vis[next]==0)
		{
			long long int nnum=dfs(next,k);
			qq.push(-nnum);
		}
	}
	while(!qq.empty())
	{
		int nnow=-qq.top();
		if(nnow+pp<=k)
		{
			pp+=nnow;
		 	qq.pop();
		}
		else break;
	}
	num+=qq.size();
	return pp;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int e=0;e<111111;e++) arr[e].clear();
		memset(val,0,sizeof(val));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int e=1;e<=n;e++) scanf("%d",&val[e]);
		for(int e=0;e<n-1;e++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		long long int left=0,right=1e15,mid,mm=1e15;
		while(left<=right)
		{
			num=0;
			memset(vis,0,sizeof(vis));
			if(mid==left){
				dfs(1,left);
				if(num<=m) printf("%lld\n",left);
				else printf("%lld\n",right);
				break;
			}
			mid=(left+right)/2;
			dfs(1,mid);
			if(num<=m)
			{
				mm=min(mm,mid);
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
	}
}
