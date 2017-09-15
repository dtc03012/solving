#include <iostream>
#include <vector>
#include <queue>
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
	int n,m;
	cin >> n >> m;
	for(int e=0;e<2*n;e+=2)
	{
		int k;
		cin >> k;
		for(int p=0;p<k;p++)
		{
			int r;
			cin >> r;
			arr[e].push_back(r);
			arr[e+1].push_back(r);
		}
	}
	int tot=0;
	for(int e=0;e<2*n;e++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(e)) tot++;
	}
	cout << tot;
}
