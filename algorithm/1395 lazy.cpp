#include <iostream>

using namespace std;
int n,m,arr[444444],lazy[444444],start=1;
int abs(int n)
{
	return n>0?n:-n;
}
void propagate(int s,int e,int node)
{
	if(lazy[node]!=0)
	{
		if(node<start)
		{
			lazy[node*2]=(lazy[node*2]+lazy[node])%2;
			lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%2;
		}
		arr[node]=abs(arr[node]-lazy[node]*(e-s));
		lazy[node]=0;
	}
}
void add(int s,int e,int node,int ns,int ne,int k)
{
	propagate(ns,ne,node);
	if(s>=ne||e<=ns) return;
	if(ns>=s&&e>=ne)
	{
		lazy[node]=(lazy[node]+k)%2;
		propagate(ns,ne,node);
		return;
	}
	int mid=(ns+ne)/2;
	add(s,e,node*2,ns,mid,k);
	add(s,e,node*2+1,mid,ne,k);
	arr[node]=arr[node*2]+arr[node*2+1];
}
int sum(int s,int e,int ns,int ne,int node)
{
	propagate(ns,ne,node);
	if(ns>=e||s>=ne) return 0;
	if(s<=ns&&ne<=e) return arr[node];
	int mid=(ns+ne)/2;
	return sum(s,e,ns,mid,node*2)+sum(s,e,mid,ne,node*2+1);
}
int main(void)
{
	cin >> n >> m;
	while(n>start) start*=2;
	for(int e=0;e<m;e++)
	{
		int a,b,c;
		cin >> a >> b>> c;
		if(a==0)
		{
			add(b-1,c,1,0,start,1);
		}
		if(a==1)
		{
			cout << sum(b-1,c,0,start,1) << endl;
		}
	}
}
