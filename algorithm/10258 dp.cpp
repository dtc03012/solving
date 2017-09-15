#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int arr[32],pp=2,dp[33];
string tmp;
int main(void)
{
	int n;
	cin >> n;
	for(int e=1;e<32;e++)
	{
		arr[e]=pp-1;
		pp*=2;
	}
	while(n--)
	{
		int kk;
		cin >> tmp;
		memset(dp,0,sizeof(dp));
		if(tmp[tmp.size()-1]=='1') dp[tmp.size()-1]=1;
		for(int e=tmp.size()-2;e>=0;e--)
		{
			kk=0;
			if(tmp[e]=='0') 
			{
				dp[e]=dp[e+1];
				continue;
			}
			for(int p=e+1;p<=tmp.size();p++)
			{
				kk+=1+arr[tmp.size()-p];
				if(p!=tmp.size()&&tmp[p]=='1')
				{
					kk+=dp[p+1];
					break;
				}
			}
			dp[e]=kk;
		}
		cout << dp[0] << "\n";
	}
}
