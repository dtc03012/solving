#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> arr[1111];
int vis[1111],finished[1111],sn[1111],SN,curr,dp[1111],check[1111],val[1111],come[1111],ma[1111],mi[1111],m;
vector<vector<int> > scc;
vector<int> ga[1111],rr;
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
		else if(finished[next]==0) result=min(result,vis[next]); 
	}
	if(result==vis[n])
	{
		vector<int> kk;
		while(1)
		{
			int now=s.top();s.pop();
			finished[now]=1;
			sn[now]=SN;
			kk.push_back(now);
			if(now==n) break;
		}
		SN++;
		scc.push_back(kk);
	}
	return result;
}
void dfs2(int now)
{
	for(int e=0;e<ga[now].size();e++)
	{
		dfs2(ga[now][e]);
		ma[now]+=ma[ga[now][e]];
	}
}

int main(void)
{
	int n;
	cin >> n >> m;
	for(int e=1;e<=n;e++)
	{
		int k;
		cin >> k;
		arr[k].push_back(e);
	}
	for(int e=1;e<=n;e++) if(vis[e]==0) dfs(e);
	for(int e=1;e<=n;e++)
	{
		for(int p=0;p<arr[e].size();p++)
		{
			int next=arr[e][p];
			if(sn[e]!=sn[next])
			{
				check[sn[next]]++;
				come[sn[next]]++;
				ga[sn[e]].push_back(sn[next]);
			}
		}
	}
	for(int e=0;e<SN;e++) val[e]=scc[e].size();
	queue<int> q;
	for(int e=0;e<SN;e++)
	{
		ma[e]=val[e];
		mi[e]=val[e];
	}
	for(int e=0;e<SN;e++)
	{
		if(check[e]==0)
		{
			dfs2(e);
		}
	}
	dp[0]=1;
	for(int e=0;e<SN;e++)
	{
		if(check[e]==0)
		{
			int kk[1111];
			for(int p=0;p<=m;p++) kk[p]=dp[p];
			for(int p=mi[e];p<=ma[e];p++)
			{
				if(p>m) continue;
				for(int q=p;q<=m;q++)
				{
					if(kk[q-p]) dp[q]=1;
				}
			}
		}
	}
	for(int q=m;q>=0;q--)
	{
		if(dp[q]) 
		{
			cout << q;
			return 0;
		}
	}
} 
