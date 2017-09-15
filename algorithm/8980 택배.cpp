#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > arr[2222];
int n,k,qq,dp[2222],tot,a,b,c;
int main(void)
{
	cin >> n >> k >> qq;
	while(qq--)
	{
		cin >> a >> b >> c;
		arr[b].push_back(make_pair(a,c));
	}
	for(int e=0;e<2222;e++) sort(arr[e].begin(),arr[e].end());
	for(int e=1;e<=n;e++)
	{
		for(int p=0;p<arr[e].size();p++)
		{
			int wh=arr[e][p].first,cost=arr[e][p].second,mins=cost;
			for(int p=wh;p<e;p++) mins=min(mins,k-dp[p]);
			for(int p=wh;p<e;p++) dp[p]+=mins;
			tot+=mins;
		}
	}
	cout << tot;
}

