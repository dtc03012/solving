#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int> arr[1111111];
long long int vis[1111111],num,cal[1111111];
int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			arr[a].push_back(a);
			num++;
			cal[a]++;
			continue;
		}
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int poss=0;
	for(int e=1;e<=n;e++)
	{
		if(arr[e].size()==0) continue;
		if(poss&&vis[e]==0)
		{
			printf("0");
			return 0;
		}
		poss++;
		queue<int> q;
		q.push(e);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			if(vis[now]) continue;
			vis[now]=1;
			for(int p=0;p<arr[now].size();p++)
			{
				int next=arr[now][p];
				if(vis[next]==0) q.push(next);
			}
		}
	}
	long long int tot=0;
	for(int e=1;e<=n;e++)
	{
		long long int pp=arr[e].size();
		tot+=(pp*(pp-1))/2;
		if(cal[e]) tot+=m-arr[e].size();
	}
	cout << tot - (num*(num-1))/2;
}
