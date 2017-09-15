#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string tmp;
int dp[33][33];
int recur(int f,int s)
{
	if(f>=s) return 0;
	if(dp[f][s]!=-1) return dp[f][s];
	dp[f][s]=0;
	int pp=0;
	for(int e=f+1;e<=s;e++) if(tmp[e]!=tmp[e-1]) pp++;
	if(pp==0) {  
		dp[f][s]=1;
		return dp[f][s];
	}
	for(int e=f+1;e<s;e++)
	{
		int vis[33];
		memset(vis,0,sizeof(vis));
		vis[e]=1;
		for(int p=e+1;p<s;p++)
		{
			vis[p]=1;
			if(recur(e,p))
			{
				int pp=0,qq=-1,rr=0;
				for(int q=f;q<=s;q++)
				{
					if(vis[q]==0)
					{
						rr++;
						if(qq==-1) qq=tmp[q]-'a';
						else if(qq!=tmp[q]-'a') pp++;
					}
				}
				if(pp==0&&rr>1) {
					dp[f][s]=1;
					return dp[f][s];
				}
			}
		}
	}
	for(int e=f+1;e<s-1;e++) if(recur(f,e)&&recur(e+1,s)) dp[f][s]=1;
	return dp[f][s];
}
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> tmp;
		memset(dp,-1,sizeof(dp));
		cout << recur(0,tmp.size()-1) << "\n";
	}
}
