#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n,m,depth[222222],parent[222222][19],subsize[222222],hpi[222222],segc[222222];
vector<int> arr[222222];
vector<vector<int> > hps,seg;
void segment()
{
	for(int e=0;e<hps.size();e++)
	{
		int ssize=hps[e].size()-1;
		seg.push_back(vector<int>(4*ssize,0));
		int pp=1;
		while(ssize>pp) pp*=2;
		segc[e]=pp;
		for(int p=1;p<2*pp;p++) seg[e][p]=1;
	}
}
void dfs2(int root)
{
	memset(hpi,-1,sizeof(hpi));
	hps.clear();
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int e=0;e<arr[now].size();e++) q.push(arr[now][e]);
		if(root==now) continue;
		int up=parent[now][0];
		if(subsize[now]*2>=subsize[up]&&up!=root)
		{
			int rr=hpi[up];
			hpi[now]=rr;
			hps[rr].push_back(now);
		}
		else
		{
			hpi[now]=hps.size();
			hps.push_back(vector<int>(2));
			hps.back()[0]=up;
			hps.back()[1]=now;
		}
	}
}
void dfs(int nn)
{
	subsize[nn]=1;
	for(int e=0;e<arr[nn].size();e++)
	{
		int next=arr[nn][e];
		if(depth[next]==-1)
		{
			parent[next][0]=nn;
			depth[next]=depth[nn]+1;
			dfs(next);
			subsize[nn]+=subsize[next];
		}
	}
}
int lca(int a,int b)
{
	int tmp=a;
	if(depth[a]<depth[b])
	{
		a=b;
		b=tmp;
	}
	int diff=depth[a]-depth[b];
	for(int p=0;diff;p++)
	{
		if(diff%2) a=parent[a][p];
		diff/=2;
	}
	if(a==b) return a;
	if(a!=b)
	{
		for(int e=17;e>=0;e--)
		{
			if(parent[a][e]!=parent[b][e]&&parent[a][e]!=-1)
			{
				a=parent[a][e];
				b=parent[b][e];
			}
		}
	}
	return parent[a][0];
}
int finds(int path,int v)
{
	return depth[v]-depth[hps[path][0]];
}
int segcal(int f,int s,int wh)
{
	int tt=98765321;
	f+=segc[wh];s+=segc[wh];
	while(f<=s)
	{
		if(f%2)
		{
			tt=min(tt,seg[wh][f]);
			f++;
		}
		if(!(s%2))
		{
			tt=min(tt,seg[wh][s]);
			s--;
		}
		f/=2;
		s/=2;
	}
	return tt;
}
int query2(int up,int down)
{
	if(up==down) return 1;
	if(hpi[up]==hpi[down])
	{
		int now=hpi[up];
		int first=finds(now,up),second=finds(now,down)-1;
		return segcal(first,second,now);
	}
	return min(query2(up,hps[hpi[down]][0]),segcal(0,finds(hpi[down],down)-1,hpi[down]));
}
int query(int a,int b)
{
	int t=lca(a,b);
	return min(query2(t,a),query2(t,b));	
}
void update(int a)
{
	if(a==1) return;
	int now=finds(hpi[a],a);
	seg[hpi[a]][now+segc[hpi[a]]-1]=0;
	for(int e=(now+segc[hpi[a]]-1)/2;e>=1;e/=2) seg[hpi[a]][e]=min(seg[hpi[a]][e*2],seg[hpi[a]][e*2+1]);
}
int main(void)
{
	memset(depth,-1,sizeof(depth));
	memset(parent,-1,sizeof(parent));
	scanf("%d%d",&n,&m);
	for(int e=2;e<=n;e++)
	{
		int k;
		scanf("%d",&k);
		arr[k].push_back(e);
	}
	depth[1]=0;
	dfs(1);
	for(int e=0;e<18;e++)
	{
		for(int p=2;p<=n;p++)
		{
			if(parent[p][e]!=-1) parent[p][e+1]=parent[parent[p][e]][e];
		}
	}
	dfs2(1);
	segment();
	for(int e=0;e<m;e++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c==1)
		{
			int now=query(a,b);
			if(now==1) 
			{
				printf("YES\n");
				update(a);
			}
			else 
			{
				printf("NO\n");
				update(b);
			}
		}
		else
		{
			if(query(a,b)==1) printf("YES\n");
			else printf("NO\n");
		}
	}
}
