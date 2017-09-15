#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define M 10001
using namespace std;
string tmp[111];
struct inf{
	int next,cap,flow;
	inf(int a,int b,int c) : next(a),cap(b),flow(c) {}
};
vector<inf> f[11111];
int n,m,arr[111][111],pp=1,source,sink,dy[4]={1,0,-1,0},dx[4]={0,1,0,-1};
bool tmr(int y,int x)
{
	if(0<=y&&y<n&&0<=x&&x<m) return true;
	return false;
}
int main(void)
{
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> tmp[e];
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(tmp[e][p]=='#') arr[e][p]=-1;
			else
			{
				arr[e][p]=pp;
				if(tmp[e][p]=='K') source=pp;
				if(tmp[e][p]=='H') sink=pp;
				pp++;
			}
		}
	}
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			if(arr[e][p]==-1) continue;
			if(arr[e][p]==source||arr[e][p]==sink)
			{
				f[arr[e][p]].push_back(inf(arr[e][p]+M,987654321,0));
				f[arr[e][p]+M].push_back(inf(arr[e][p],0,0));
			}
			else
			{
				f[arr[e][p]].push_back(inf(arr[e][p]+M,1,0));
				f[arr[e][p]+M].push_back(inf(arr[e][p]+M,0,0));
			}
			int tt=0;
			for(int q=0;q<4;q++)
			{
				int nexty=e+dy[q],nextx=p+dx[q];
				if(tmr(nexty,nextx)&&arr[nexty][nextx]!=-1)
				{
					f[arr[e][p]+M].push_back(inf(arr[nexty][nextx],1,0));
					f[arr[nexty][nextx]].push_back(inf(arr[e][p]+M,0,0));
					f[arr[nexty][nextx]+M].push_back(inf(arr[e][p],1,0));
					f[arr[e][p]].push_back(inf(arr[nexty][nextx]+M,0,0));
					if(arr[e][p]==source&&arr[nexty][nextx]==sink) tt++;
				}
			}
			if(tt)
			{
				cout << "-1";
				return 0;
			}
		}
	}
	int tot=0;
	while(1)
	{
		vector<pair<int,int> > parent(11111,pair<int,int>(-1,-1));
		queue<int> q;
		q.push(source);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			for(int e=0;e<f[now].size();e++)
			{
				inf next=f[now][e];
				if(next.cap-next.flow>0&&parent[next.next].first==-1)
				{
					q.push(next.next);
					parent[next.next].first=now;
					parent[next.next].second=e;
				}
			}
		}
		if(parent[sink+M].first==-1) break;
		int amount=987654321;
		for(int e=sink+M;e!=source;e=parent[e].first) amount=min(amount,f[parent[e].first][parent[e].second].cap-f[parent[e].first][parent[e].second].flow);
		for(int e=sink+M;e!=source;e=parent[e].first)
		{
			f[parent[e].first][parent[e].second].flow+=amount;
			for(int k=0;k<f[e].size();k++)
			{
				if(f[e][k].next==parent[e].first)
				{
					f[e][k].flow-=amount;
				}
			}
		}
		tot+=amount;
	}
	cout << tot;
}
