#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[1111];
int a[1111],b[1111],vis[1111];
int dfs(int n)
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
		}
	}
	int tot=0;
	for(int e=0;e<n;e++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(e)) tot++;
	}
	for(int e=0;e<n;e++)
	{
		while(dfs(e)&&k)
		{
			memset(vis,0,sizeof(vis));
			tot++;
			k--;
		}
	}
	cout << tot;
}
