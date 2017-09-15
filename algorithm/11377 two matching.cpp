#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[2222];
int a[2222],b[2222],vis[2222];
bool dfs(int n)
{
	vis[n]=1;
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e];
		if(b[next]==-1||vis[b[next]]==0&&dfs(b[next]))
		{
			b[next]=n;
			a[n]=next;
			return true;
		}
	}
	return false;
}
int main(void)
{
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	int n,m,k;
	cin >> n >> m >> k;
	for(int e=0;e<n;e++)
	{
		int r;
		cin >> r;
		for(int p=0;p<r;p++)
		{
			int t;
			cin >> t;
			arr[e].push_back(t);
			arr[e+n].push_back(t);
		}
	}
	int tot=0;
	for(int e=0;e<2*n;e++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(e))
		{
			tot++;
			if(e>=n) k--;
		}
		if(k==0) break;
	}
	cout << tot;
}
