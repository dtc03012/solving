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
	if(s<=ns&&ne<=e)
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
int main(void)
{
	printf("ASdf");
	//scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&row,&m);
	while(M>start) start*=2;
	for(int e=0;e<m;e++)
	{
		int p,q,r,y;
		scanf("%d%d%d%d",&p,&q,&r,&y);
		int fx=r-row,sx=p,fy=q,sy=d+row;
		if(fx<a) fx=a;
		if(sy>b) sy=b;
		inf kk;
		kk.x=fx;
		kk.sy=fy;
		kk.ey=sy;
		kk.type=0;
		printf("asdf %d %d %d %d %d\n",fx,sx,fy,sy,sx);
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
		ma=max(ma,seg[1]);
	}
	printf("%d",ma);
}
