#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
vector<int> arr[11111];
int a[11111],b[11111],vis[11111],maps[111][111],maps2[111][111];
string tmp[111];
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
	int n,pp=1;
	cin >> n;
	for(int e=0;e<n;e++) cin >> tmp[e];
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<n;p++)
		{
			if(tmp[e][p]=='.')
			{
				if(e>0)
				{
					if(maps[e-1][p]!=0)
					{
						maps[e][p]=maps[e-1][p];
						continue;
					}
				}
				maps[e][p]=pp;
				pp++;
			}
		}
	}
	pp=1;
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<n;p++)
		{
			if(tmp[p][e]=='.')
			{
				if(e>0)
				{
					if(maps2[p][e-1]!=0)
					{
						maps2[p][e]=maps2[p][e-1];
						continue;
					}
				}
				maps2[p][e]=pp;
				pp++;
			}
		}
	}
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<n;p++)
		{
			if(maps[e][p]!=0)
			{
				arr[maps2[e][p]].push_back(maps[e][p]);
			}
		}
	}
	int tot=0;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(int e=1;e<pp;e++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(e)) tot++;
	}
	cout << tot;
}
