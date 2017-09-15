#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
string tmp[22];
int a[7][7]={{10,8,7,5,0,1},{8,6,4,3,0,1},{7,4,3,2,0,1},{5,3,2,2,0,1},{0,0,0,0,0,0},{1,1,1,1,0,0}};
int dp[16][33333],ma,n,m;
void recur(int now,int bit,int upbit,int tot)
{
	ma=max(ma,tot);
	if(n==now) return;
	for(int e=0;e<m;e++)
	{
		if((bit&(1<<e))) continue;
		if(e<m-1) 
		{
			if((bit&(1<<(e+1)))==0) 
			{
				int nextbit=((bit|(1<<e))|(1<<(e+1)));
				if(dp[now][nextbit]<tot+a[tmp[now][e]-'A'][tmp[now][e+1]-'A'])
				{
					dp[now][nextbit]=tot+a[tmp[now][e]-'A'][tmp[now][e+1]-'A'];
					recur(now,nextbit,upbit,tot+a[tmp[now][e]-'A'][tmp[now][e+1]-'A']);
					recur(now+1,0,nextbit,tot+a[tmp[now][e]-'A'][tmp[now][e+1]-'A']);
				}
			}
		}
		if(now>0) 
		{
			if((upbit&(1<<e))==0) 
			{
				int nextbit=(bit|(1<<e));
				if(dp[now][nextbit]<tot+a[tmp[now][e]-'A'][tmp[now-1][e]-'A'])
				{
					dp[now][nextbit]=tot+a[tmp[now][e]-'A'][tmp[now-1][e]-'A'];
					recur(now,nextbit,(upbit|(1<<e)),tot+a[tmp[now][e]-'A'][tmp[now-1][e]-'A']);
					recur(now+1,0,nextbit,tot+a[tmp[now][e]-'A'][tmp[now-1][e]-'A']);
				}
			}
		}
	}
	recur(now+1,0,bit,tot);
} 
int main(void)
{
	memset(dp,-1,sizeof(dp));
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> tmp[e];
	recur(0,0,0,0);
	cout << ma;
}
