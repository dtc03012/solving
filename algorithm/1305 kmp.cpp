#include <iostream>
#include <string>
using namespace std;
int dp[1111111],n;
string tmp;
int main(void)
{
	cin >> n >> tmp;
	tmp=" "+tmp;
	for(int e=2;e<tmp.size();e++)
	{
		int v=dp[e-1];
		while(1)
		{
			if(tmp[e]==tmp[v+1])
			{
				dp[e]=v+1;
				break;	
			}	
			if(v==0) break;
			v=dp[v];
		}	
	}
	for(int e=tmp.size()-1;e>=1;e--)
	{
		if(dp[e]*2<=e)
		{
			cout << e-dp[e];
			break;
		}
	}
}
