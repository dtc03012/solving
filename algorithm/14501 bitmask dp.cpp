#include <iostream>
#include <string.h>
using namespace std;
pair<int,int> arr[22];
int dp[44444],ma,n;
void bitmask(int now,int bit,int tot)
{
	if(dp[bit]>=tot) return;
	dp[bit]=tot;
	ma=max(ma,tot);
	for(int e=now;e<n;e++)
	{
		if(e+arr[e].first-1<n)
		{
			bitmask(e+arr[e].first,bit|(1<<e),tot+arr[e].second);
		}
	}
}
int main(void)
{
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(int e=0;e<n;e++)
	{
		cin >> arr[e].first >> arr[e].second;
	}
	bitmask(0,0,0);
	cout << ma;
}
