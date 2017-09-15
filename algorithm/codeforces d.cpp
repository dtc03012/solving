#include <stdio.h>
#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
long long int n,arr[222222],dp[222222],rr[1111111];
long long int kk[1111111][2];
vector<int> sosu;
int main(void)
{
	for(int e=2;e<=1000000;e++) if(rr[e]==0) for(int p=e*2;p<=1000000;p+=e) rr[p]=1;
	for(int e=2;e<=1000000;e++) if(rr[e]==0) sosu.push_back(e);
	scanf("%lld",&n);
	for(int e=0;e<n;e++) scanf("%lld",&arr[e]);
	for(int e=0;e<n;e++)
	{
		if(e>0) dp[e]=dp[e-1];
		vector<int> ttt;
		for(int p=0;p<sosu.size();p++)
		{
			if(arr[e]%sosu[p]==0)
			{
				ttt.push_back(sosu[p]);
				while(arr[e]%sosu[p]==0) arr[e]/=sosu[p];
			}
		}
		for(int p=0;p<ttt.size();p++)
		{
			int now=ttt[p];
			dp[e]=(dp[e]+(kk[now][0]+kk[now][1]+1)*now)%mod;
			kk[now][0]=(kk[now][0]*2+1+kk[now][1])%mod;
			kk[now][1]=(kk[now][1]*2+1)%mod;
		}
	}
	printf("%lld",dp[n-1]);
}
