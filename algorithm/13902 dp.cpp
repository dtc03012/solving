#include <iostream>
#include <string.h>
using namespace std;
int dp[11111],n,m,k;

int main(void)
{
	cin >> n >> m;
	memset(dp,-1,sizeof(dp));
	dp[0]=1;
	for(int e=0;e<m;e++)
	{
		cin >> k;
		int arr[11111];
		memset(arr,-1,sizeof(arr));
		for(int p=0;p<k;p++) arr[p]=dp[p];
		for(int p=k;p<=n;p++) 
		{
			int mm=987654321;
			if(arr[p-k]!=-1) mm=min(mm,arr[p-k]+1);
			if(dp[p-k]!=-1) mm=min(mm,dp[p-k]);
			arr[p]=mm;
		}
		for(int p=0;p<=n;p++) dp[p]=arr[p];
		for(int p=1;p<=n;p++) cout << dp[p] << " ";
		cout << endl;
	}
	if(dp[n]==987654321) cout << "-1";
	else cout << dp[n];
}
