#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n,m;
double s,v;
vector<pair<double,double> > ff,ss;
vector<int> arr[111];
int aa[111],bb[111],vis[111];
double abs(double a)
{
	return a>0?a:-a;
}
bool dfs(int n)
{
	vis[n]=1;
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e];
		if(bb[next]==-1||vis[bb[next]]==0&&dfs(bb[next]))
		{
			aa[n]=next;
			bb[next]=n;
			return true;
		}
	}
	return false;
}
int main(void)
{
	memset(aa,-1,sizeof(aa));
	memset(bb,-1,sizeof(bb));
	cin >> n >> m >> s >> v;
	for(int e=0;e<n;e++)
	{
		double a,b;
		cin >> a >> b;
		ff.push_back(make_pair(a,b));
	}
	for(int e=0;e<m;e++)
	{
		double a,b;
		cin >> a >> b;
		ss.push_back(make_pair(a,b));
	}
	for(int e=0;e<ff.size();e++)
	{
		for(int p=0;p<ss.size();p++)
		{
			double kk=(ff[e].first-ss[p].first)*(ff[e].first-ss[p].first)+(ff[e].second-ss[p].second)*(ff[e].second-ss[p].second);
			if(kk<=v*v*s*s)
			{
				arr[e].push_back(p);
			}
		}
	}
	int tot=0;
	for(int e=0;e<ff.size();e++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(e)) tot++;
	}
	cout << ff.size()-tot;
}
