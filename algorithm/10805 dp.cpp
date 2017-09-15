#include <iostream>
#include <string.h>
using namespace std;
int h1,h2,w1,w2,ma,dp[55][55][55][55];
int recur(int y,int x)
{
	if(dp[y][x][0][0]!=-1) return dp[y][x][0][0];
	dp[y][x][0][0]=987654321;
	for(int e=1;e<=x;e++)
	{
		dp[y][x][0][0]=min(dp[y][x][0][0],recur(y,x-e)+recur(y,e));
	}
	for(int e=1;e<=y;e++)
	{
		dp[y][x][0][0]=min(dp[y][x][0][0],recur(e,x)+recur(y-e,x));
	}
	dp[x][y][0][0]=dp[y][x][0][0];
	return dp[y][x][0][0];
}
int main(void)
{
	cin >> h1 >> w1 >> h2 >> w2;
	memset(dp,-1,sizeof(dp));
	for(int e=50;e>=1;e--) 
	{
		dp[e][0][0][0]=0;
		dp[0][e][0][0]=0;
		dp[e][e][0][0]=1;
	}
	for(int e=1;e<=50;e++) for(int p=1;p<=50;p++) if(dp[e][p][0][0]==-1) recur(e,p);
	for(int e=1;e<=h1;e++) // h1
	{
		for(int p=1;p<=w1;p++) // w1
		{
			for(int q=1;q<e;q++) // h2
			{
				for(int r=1;r<p;r++) //w2
				{
					dp[e][p][q][r]=987654321;
					for(int c=1;c<p-r;c++) dp[e][p][q][r]=min(dp[e][p][q][r],dp[e][c][0][0]+dp[e][p-c][q][r]);
					dp[e][p][q][r]=min(dp[e][p][q][r],dp[e][p-r][0][0]+dp[e-q][r][0][0]);
					for(int c=p-r+1;c<p;c++) dp[e][p][q][r]=min(dp[e][p][q][r],dp[e-q][p-c][0][0]+dp[e][c][q][c-p+r]);
					for(int c=1;c<q;c++) dp[e][p][q][r]=min(dp[e][p][q][r],dp[c][p-r][0][0]+dp[e-c][p][q-c][r]);
					dp[e][p][q][r]=min(dp[e][p][q][r],dp[q][p-r][0][0]+dp[e-q][p][0][0]);
					for(int c=q+1;c<e;c++) dp[e][p][q][r]=min(dp[e][p][q][r],dp[e-c][p][0][0]+dp[c][p][q][r]);
				}
			}
		}
	}
	
	cout <<	dp[h1][w1][h2][w2];
}
