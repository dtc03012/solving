#include <iostream>
#include <algorithm>
using namespace std;
int arr[222],vis[222];
pair<int,int> inf[222];
pair<pair<int,int>,int> f[222],s[222];
bool tmr(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
	if(a.first.first>b.first.first) return true;
	if(a.first.first<b.first.first) return false;
	if(a.first.second>b.first.second) return true;
	return false;
}
int main(void)
{
	int n,k;
	cin >> n >> k;
	for(int e=0;e<n;e++) cin >> arr[e];
	for(int e=0;e<n;e++)
	{
		int pp=0,ss=0;
		while(arr[e]%2==0)
		{
			arr[e]/=2;
			pp++;
		}
		while(arr[e]%5==0)
		{
			arr[e]/=5;
			ss++;
		}
		inf[e]=make_pair(pp,ss);
		f[e]=make_pair(make_pair(pp,ss),e);
		s[e]=make_pair(make_pair(ss,pp),e);
	}
	sort(f,f+n,tmr);
	sort(s,s+n,tmr);
	int pp=0,ff=0,ss=0;
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<n;p++)
		{
			if(vis[p]==1) continue;
			if(f[e].second==s[p].second) continue;
			if(pp==k) continue;
			pp++;
			vis[p]=1;
			ff+=f[e].first.first+s[p].first.second;
			ss+=f[e].first.second+s[p].first.first;
		}
	}
	cout << min(ff,ss);
}
