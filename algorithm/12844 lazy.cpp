#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int arr[555555],seg[555555*4],lazy[4*555555],n,start=1,m;
void propagate(int s,int e,int node)
{
	if(lazy[node]!=0)
	{
		if(node<start)
		{
			lazy[node*2]^=lazy[node];
			lazy[node*2+1]^=lazy[node];
		}
		if(((e-s)%2))seg[node]^=lazy[node];
		lazy[node]=0;
	}
}
void add(int s,int e,int node,int ns,int ne,int k)
{
	propagate(ns,ne,node);
	if(s>=ne||e<=ns) return;
	if(ns>=s&&ne<=e)
	{
		lazy[node]^=k;
		propagate(ns,ne,node);
		return;
	}
	int mid=(ns+ne)/2;
	add(s,e,node*2,ns,mid,k);
	add(s,e,node*2+1,mid,ne,k);
	seg[node]=seg[node*2]^seg[node*2+1];
}
int sum(int s,int e,int ns,int ne,int node)
{
	propagate(ns,ne,node);
	if(ns>=e||s>=ne) return 0;
	if(ns>=s&&e>=ne) return seg[node];
	int mid=(ns+ne)/2;
	return sum(s,e,ns,mid,node*2)^sum(s,e,mid,ne,node*2+1);
}
int main(void)
{
	scanf("%d",&n);
	while(n>start) start*=2;
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);
	for(int e=start;e<start+n;e++) seg[e]=arr[e-start];
	for(int e=start-1;e>0;e--) seg[e]=seg[e*2]^seg[e*2+1];
	scanf("%d",&m);
	for(int e=0;e<m;e++)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			add(min(b,c),max(b,c)+1,1,0,start,d);
		}
		if(a==2)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			printf("%d\n",sum(min(b,c),max(b,c)+1,0,start,1));
		}
		
	}
}
