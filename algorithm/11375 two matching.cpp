#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[1111];
int a[1111],b[1111],vis[1111],n,m,k,r;
bool dfs(int n)
{
	vis[n]=1;
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e];
		if(b[next]==-1||vis[b[next]]==0&&dfs(b[next]))
		{
			a[n]=next;
			b[next]=n;
			return true;
		}
	}
	return false;
}
int main(void)
{
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	cin >> n >> m;
	for(int e=0;e<n;e++)
	{
		cin >> k;
		for(int p=0;p<k;p++)
		{
			cin >> r;
			arr[e].push_back(r);
		}
	}
	int tot=0;
	for(int e=0;e<n;e++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(e)) tot++;
	}
	cout << tot;
}
