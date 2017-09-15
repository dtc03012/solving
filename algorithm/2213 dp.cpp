#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,val[11111],vis[11111],dp[11111];
vector<int> arr[11111],parent[11111];
void dfs(int now)
{
	vis[now]=1;
	for(int p=0;p<arr[now].size();p++)
	{
		int next=arr[now][p];
		if(vis[next]==0) dfs(next);
		else continue;
		for(int q=0;q<arr[next].size();q++)
		{
			int nnext=arr[next][q];
			if(nnext==now) continue;
			int kkk=0;
			vector<int> kr;
			for(int r=0;r<arr[nnext].size();r++)
			{
				int nnnext=arr[nnext][r];
				if(nnnext==next) continue;
				kkk+=dp[nnnext];
				kr.push_back(nnnext);
			}
			if(dp[nnext]>kkk)
			{
				dp[now]+=dp[nnext];
				parent[now].push_back(nnext);
			}
			else
			{
				dp[now]+=kkk;
				for(int r=0;r<kr.size();r++) parent[now].push_back(kr[r]);
			}
		}
	}
	dp[now]+=val[now];
}
int main(void)
{
	cin >> n;
	for(int e=1;e<=n;e++) cin >> val[e];
	for(int e=0;e<n-1;e++)
	{
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
	int kk=0,ss;
	for(int e=1;e<=n;e++) if(dp[e]>kk)
	{
		kk=dp[e];
		ss=e;
	}
	cout << kk << "\n";
	queue<int> q;
	q.push(ss);
	vector<int> rs;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		rs.push_back(now);
		for(int p=0;p<parent[now].size();p++)
		{
			if(parent[now][p]!=0)
			{
				q.push(parent[now][p]);
			}
		}
	}
	sort(rs.begin(),rs.end());
	for(int e=0;e<rs.size();e++) cout << rs[e] << " "
;}
