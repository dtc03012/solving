#include <iostream>
#include <math.h>
#include <vector>
#define m 1000000007
using namespace std;
long long int dp[5555555],arr[5555555];
vector<int> rrr;
int main(void)
{
	for(int e=2;e<=5555555;e++) if(arr[e]==0) for(int p=e*2;p<=5555555;p+=e) arr[p]=1;
	for(int e=2;e<=5555555;e++) if(arr[e]==0) rrr.push_back(e);
	
	long long int a,b,c,k=1,pp=0;
	cin >> a >> b >> c;
	dp[2]=1;
	dp[3]=3;
	dp[4]=3;
	for(long long int e=5;e<=c;e++)
	{
		dp[e]=((e*(e-1))/2)%m;
		if(arr[e]==0) continue;
		for(int p=0;p<rrr.size();p++)
		{
			if(rrr[p]>=e) break; 
			if(e%rrr[p]==0)
			{
			//	dp[e]=min(dp[e],(((e*(rrr[p]-1)/2)%m+dp[e/rrr[p]])%m));
				dp[e]=min(dp[e],(((e*((e/rrr[p])-1)/2)%m+dp[rrr[p]])%m));
				break;
			}
		}
	}
	for(int e=b;e<=c;e++)
	{
		pp=(pp+k*dp[e])%m;
		k=(k*a)%m;
	}
	cout << pp;
}
