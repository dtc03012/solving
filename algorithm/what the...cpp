#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define M 1111111
using namespace std;
struct inf{
	int x,sy,ey,type;
};
vector<inf> arr;
int seg[M*4],lazy[M*4],start=1,ma;
	int a,b,c,d,row,m;
bool tmr(inf a,inf b)
{
	if(a.x<b.x) return true;
	if(a.x>b.x) return false;
	if(a.type<=b.type) return true;
	if(a.type>b.type) return false;
	if(a.sy<b.sy) return true;
	return false;
}
void propagate(int s,int e,int node)
{
	if(lazy[node]!=0)
	{
		if(node<start)
		{
			if(node*2+1>=4*M) return ;
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		seg[node]+=lazy[node];
		lazy[node]=0;
	}
}
int sum(int s,int e,int ns,int ne,int node)
{
	propagate(ns,ne,node);
	if(ns>=e||s>=ne) return 0;
	if(node>=4*M) return 0;
	if(ns>=s&&e>=ne) return seg[node];
	int mid=(ns+ne)/2;
	return max(sum(s,e,ns,mid,node*2),sum(s,e,mid,ne,node*2+1));
}
void add(int s,int e,int node,int ns,int ne,int k)
{
	propagate(ns,ne,node);
	if(s>=ne||e<=ns) return;
	if(s<=ns&&ne<=e)
	{
		if(node>=4*M) return;
		lazy[node]+=k;
		propagate(ns,ne,node);
		return;
	}
	int mid=(ns+ne)/2;
	add(s,e,node*2,ns,mid,k);
	add(s,e,node*2+1,mid,ne,k);
	if(node*2+1>=4*M) return;
	seg[node]=max(seg[node*2],seg[node*2+1]);
}
int main(void)
{
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&row,&m);
	while(M>start) start*=2;
	for(int e=0;e<m;e++)
	{
		int p,q,r,y;
		scanf("%d%d%d%d",&p,&q,&r,&y);
		int fx=r-row,sx=p,fy=q,sy=y+row;
		if(fx<a) fx=a;
		if(sy>b) sy=b;
		inf kk;
		kk.x=fx;
		kk.sy=fy;
		kk.ey=sy;
		kk.type=0;
		arr.push_back(kk);
		kk.x=sx;
		kk.type=1;
		arr.push_back(kk);
	}
	sort(arr.begin(),arr.end(),tmr);
	for(int e=0;e<arr.size();e++)
	{
		if(arr[e].type==0) add(arr[e].sy,arr[e].ey+1,1,0,start,1);
		else add(arr[e].sy,arr[e].ey+1,1,0,start,-1);
		ma=max(ma,sum(0,start,0,start,1));
	}
	printf("%d",ma);
}
