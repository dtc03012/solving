#include <stdio.h>
#define mod 1000007
int arr[55][55],dp[55][55][55][55],n,m,k;
int main(void)
{
	scanf("%d%d%d",&n,&m,&k);
	for(int e=1;e<=k;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a][b]=e;
	}
	if(arr[1][1]==0)
	{
		dp[1][1][0][0]=1;
	}
	else
	{
		dp[1][1][1][arr[0][0]]=1;
	}
	for(int e=1;e<=n;e++)
	{
		for(int p=1;p<=m;p++)
		{
			if(e==1&&p==1) continue;
			if(arr[e][p]==0)
			{
				for(int r=0;r<=k;r++)
				{
					for(int y=0;y<=k;y++) dp[e][p][r][y]=(dp[e-1][p][r][y]+dp[e][p-1][r][y])%mod;
				}
			}
			else
			{
				for(int r=1;r<=k;r++) //사람의 수 
				{
					for(int q=0;q<arr[e][p];q++)
					{
						dp[e][p][r][arr[e][p]]=(dp[e][p][r][arr[e][p]]+dp[e-1][p][r-1][q]+dp[e][p-1][r-1][q])%mod;
					}
				}
			}
		}
	}
	for(int e=0;e<=k;e++)
	{
		int kk=0;
		for(int p=0;p<=k;p++) kk=(kk+dp[n][m][e][p])%mod;
		printf("%d ",kk);
	}
}
