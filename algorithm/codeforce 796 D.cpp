#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
vector<pair<int,int> > v[333333];
int aa[333333],now[333333],vis[333333],n,k,d,tot=0;
vector<int> inf,vv;
bool dfs(int n,int dist)
{
	int poss=0;
	vis[n]=dist;
	for(int e=0;e<v[n].size();e++)
	{
		int next=v[n][e].first,kk=0;
		if(aa[next]==0) if(dist<d) if(vis[next]>dist)
		{
			if(vis[next]==987654321)
			{
				kk++;
				poss++;
			}
			if(dfs(next,dist+1))
			{
				kk++;
				poss++;
			}
		}
		if(kk)
		{
			now[v[n][e].second]=1;
		}
	}
	if(poss) return true;
	return false;
}
int main(void)
{
	for(int e=0;e<333333;e++) vis[e]=987654321;
	scanf("%d%d%d",&n,&k,&d);
	for(int e=0;e<k;e++)
	{
		int r;
		scanf("%d",&r);
		aa[r]=1;
		vv.push_back(r);
	}
	for(int e=1;e<n;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(make_pair(b,e));
		v[b].push_back(make_pair(a,e));
	}
	for(int e=0;e<vv.size();e++) 
	{
		dfs(vv[e],0);
	}
	for(int e=1;e<n;e++) if(now[e]==0) inf.push_back(e);
	cout << inf.size() << endl;
	for(int e=0;e<inf.size();e++) cout << inf[e] << " ";
}
