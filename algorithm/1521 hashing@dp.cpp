#include <iostream>
using namespace std;
int arr[8];
double dp[20000000];
int main(void)
{
	int n;
	cin >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
}


4 3 2 1

2 1 -> 1
4 3 2 1 

3 2 1

1 2 3

3 1 2

-> #include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[3333];
int a[3333],b[3333],vis[3333],map1[55][55],map2[55][55];
string tmp[55];
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
	int n,m,pp=1;
	cin >> n >> m;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(int e=0;e<n;e++) cin >> tmp[e];
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(tmp[e][p]=='*')
			{
				if(e>0)
				{
					if(map1[e-1][p]!=0)
					{
						map1[e][p]=map1[e-1][p];
						continue;
					}
				}
				map1[e][p]=pp;
				pp++;
			}
		}
	}
	pp=1;
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(tmp[p][e]=='*')
			{
				if(e>0)
				{
					if(map2[p][e-1]!=0)
					{
						map2[p][e]=map2[p][e-1];
						continue;
					}
				}
				map2[p][e]=pp;
				pp++;
			}
		}
	}
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(map1[e][p]!=0)
			{
				arr[map1[e][p]].push_back(map2[e][p]);
			}
		}
	}
	int tot=0;
	for(int e=1;e<pp;e++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(e)) tot++;
	}
	cout << tot;
}
