#include <stdio.h>
#include <iostream>
using namespace std;
int dp[111111][5][5],tot,n,pp=1;
int arr[111111],vv[5][5];
int main(void)
{
	vv[0][0]=1;
	for(int e=1;e<=4;e++) vv[0][e]=2;
	for(int e=0;e<111111;e++) for(int p=0;p<5;p++) for(int q=0;q<5;q++) dp[e][p][q]=987654321;
	vv[1][1]=1;
	vv[1][2]=3;
	vv[1][4]=3;
	vv[1][3]=4;
	vv[2][2]=1;
	vv[2][3]=3;
	vv[2][4]=4;
	vv[3][3]=1;
	vv[3][4]=3;
	vv[4][4]=1;
	dp[0][0][0]=0;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		for(int e=0;e<5;e++)
		{
			for(int p=0;p<5;p++)
			{
				if(dp[pp-1][e][p]==987654321) continue;
				dp[pp][n][p]=min(dp[pp][n][p],dp[pp-1][e][p]+vv[min(e,n)][max(e,n)]);
				dp[pp][e][n]=min(dp[pp][e][n],dp[pp-1][e][p]+vv[min(p,n)][max(p,n)]);
			}
		}
		pp++;
	}
	int kk=987654321;
	for(int e=0;e<5;e++) for(int p=0;p<5;p++) kk=min(kk,dp[pp-1][e][p]);
	printf("%d",kk);
}

