#include <stdio.h>
int arr[35555];
int dp[55][35555];
int cc[35555];
int max(int a,int b)
{
	return a>b?a:b;
}
int main(void)
{
	int n,k,pp=1;
	scanf("%d%d",&n,&k);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=1;e<55;e++) dp[e][e]=e;
	for(int e=1;e<=k;e++)
	{
		for(int p=e+1;p<=n;p++)
		{
			int now=0;
			for(int q=p;q>=e;q--)
			{
				if(cc[arr[q]]!=pp) now++;
				cc[arr[q]]=pp;
				dp[e][p]=max(dp[e][p],now+dp[e-1][q-1]);
			}
			pp++;
		}
	}
	printf("%d",dp[k][n]);
}
