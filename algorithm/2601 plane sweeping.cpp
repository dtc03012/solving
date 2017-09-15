#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define M 1111111
using namespace std;
struct inf{
	int x,sy,ey,type;
};
vector<inf> arr;
int n,m,row,seg[3*M*4],lazy[3*M*4],ma,start=1;
void propagate(int s,int e,int node)
{
	if(lazy[node]!=0)
	{
		if(node<start)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		seg[node]+=lazy[node];
		lazy[node]=0;
	}	
}
void add(int s,int e,int node,int ns,int ne,int k)
{
	propagate(ns,ne,node);
	if(s>=ne||e<=ns) return;
	if(ns>=s&&ne<=e)
	{
		lazy[node]+=k;
		propagate(ns,ne,node);
		return;
	}
	int mid=(ns+ne)/2;
	add(s,e,node*2,ns,mid,k);
	add(s,e,node*2+1,mid,ne,k);
	seg[node]=max(seg[node*2],seg[node*2+1]);
}

bool tmr(inf a,inf b)
{
	if(a.x<b.x) return true;
	if(a.x>b.x) return false;
	if(a.type<=b.type) return true;
	if(a.type>b.type) return false;
	if(a.sy<b.sy) return true;
	return false;
}
int main(void)
{
	int a,b,c,d,k;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%d%d",&row,&k);
	while(M>start) start*=2;
	for(int e=0;e<k;e++)
	{
		int p,q,r,d;
		scanf("%d%d%d%d",&p,&q,&r,&d);
		int sy=q,ey=d+row,fx=r-row,sx=p;
		inf kk;
		if(fx<a) fx=a;
		if(ey>b) ey=b;
		kk.x=fx;
		kk.sy=sy;
		kk.ey=ey;
		kk.type=0;
		if(fx>=sx||sy>=ey) continue;
		arr.push_back(kk);
		kk.x=sx;
		kk.type=1;
		arr.push_back(kk);
	}
	sort(arr.begin(),arr.end(),tmr);
	for(int e=0;e<arr.size();e++)
	{
		if(arr[e].sy<0||arr[e].ey<0) continue;
		add(arr[e].sy,arr[e].ey+1,1,0,start,(arr[e].type==0?1:-1));
		ma=max(ma,seg[1]);
	}
	printf("%d",ma);
}
