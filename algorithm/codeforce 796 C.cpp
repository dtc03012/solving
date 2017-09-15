#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> arr[333333];
pair<int,int> aa[333333];
int ss[333333],kk[333333];
bool tmr(pair<int,int> a,pair<int,int> b)
{
	return a.first > b.first;
}
int main(void)
{
	int n,maxs=2e9;
	cin >> n;
	for(int e=1;e<=n;e++) 
	{
		int k;
		cin >> k;
		kk[e]=k;
		aa[e]=make_pair(k,e);
	}
	sort(aa+1,aa+n+1,tmr);
	for(int e=0;e<n-1;e++)
	{
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int rr=2e9+1;
	for(int e=1;e<=n;e++)
	{
		int now=e,mx=kk[e];
		ss[now]=1;
		for(int p=0;p<arr[now].size();p++)
		{
			int next=arr[now][p];
			ss[next]=1;
			mx=max(mx,kk[next]+1);
		}
		for(int p=1;p<=n;p++) if(ss[aa[p].second]==0) 
		{
			mx=max(mx,aa[p].first+2);
			break;
		}
		ss[now]=0;
		for(int p=0;p<arr[now].size();p++)
		{
			int next=arr[now][p];
			ss[next]=0;
		}
		rr=min(rr,mx);
	}
	cout << rr;
}
