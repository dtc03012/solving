#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[111111];
int dp[111111];
bool tmr(pair<int,int> a,pair<int,int> b)
{
	return a.second < b.second;
}
int main(void)
{
	int n;
	cin >> n;
	for(int e=1;e<=n;e++) cin >> arr[e].first >> arr[e].second;
	sort(arr+1,arr+n+1,tmr);
	dp[0]=1;
	dp[1]=2;
	for(int e=2;e<=n;e++)
	{
		dp[e]=dp[e-1];
		int left=1,right=e-1,mid;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(arr[mid].second>=arr[e].first)
			{
				right=mid-1;
			}
			else
			{
				left=mid+1;
			}
		}
		dp[e]=(dp[e]+dp[right])%20070713;
	}
	cout << dp[n];
}
