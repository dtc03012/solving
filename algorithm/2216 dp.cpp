#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
string tmp[55];
int pp=0,dy[4]={1,0,-1,0},dx[4]={0,1,0,-1},maps[55][55],qr=0;
vector<pair<int,int> > arr[2666];
int a[1111],b[1111],vis[1111],dist[1111];
bool dfs(int n,int kk)
{
	vis[n]=1;
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e].first,dd=arr[n][e].second;
		if(dd>kk) continue;
		if(b[next]==-1||vis[b[next]]==0&&dfs(b[next],kk))
		{
			b[next]=n;
			a[n]=next;
			dist[n]=dd;
			return true;
		}
	}
	return false;
}
bool tmr(int y,int x,int n,int m)
{
	if(0<=y&&y<n&&0<=x&&x<m) return true;
	return false;
}
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> tmp[e];
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(tmp[e][p]=='P') 
			{
				maps[e][p]=qr;
				qr++;
			}
		}
	}
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(tmp[e][p]=='C')
			{
				int vis[55][55];
				for(int q=0;q<55;q++) for(int r=0;r<55;r++) vis[q][r]=987654321;
				queue<pair<int,pair<int,int > > > qq;
				qq.push(make_pair(0,make_pair(e,p)));
				vis[e][p]=0;
				while(!qq.empty())
				{
					int tot=qq.front().first,nowy=qq.front().second.first,nowx=qq.front().second.second;qq.pop();
					vis[nowy][nowx]=tot;
					for(int q=0;q<4;q++)
					{
						int nexty=nowy+dy[q],nextx=nowx+dx[q];
						if(tmr(nexty,nextx,n,m))
						{
							if(tmp[nexty][nextx]!='X')
							{
								if(vis[nexty][nextx]>tot+1)
								{
									vis[nexty][nextx]=tot+1;
									qq.push(make_pair(tot+1,make_pair(nexty,nextx)));
								}
							}
						}
					}
				}
				for(int q=0;q<n;q++)
				{
					for(int r=0;r<m;r++)
					{
						if(tmp[q][r]=='P')
						{
							arr[pp].push_back(make_pair(maps[q][r],vis[q][r]));
						}
					}
				}
				pp++;
			}
		}
	}
	if(pp>qr) 
	{
		cout << "-1";
		return 0;
	}
	if(pp==0)
	{
		cout << "0";
		return 0;
	}
	int left=0,right=2500,mid,kk=987654321;
	while(left<=right)
	{
		memset(dist,-1,sizeof(dist));
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		mid=(left+right)/2;
		int pps=0;
		for(int e=0;e<pp;e++)
		{
			memset(vis,0,sizeof(vis));
			if(!dfs(e,mid)) pps++;
		}
		if(pps)
		{
			left=mid+1;
		}
		else
		{
			int rt=0;
			for(int e=0;e<pp;e++) rt=max(rt,dist[e]);
			kk=min(kk,rt);
			right=mid-1;
		}
	}
	if(kk==987654321) cout <<"-1";
	else cout << kk << endl;
}
