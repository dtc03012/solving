#include <stdio.h>
#include <string.h>
int dp[16][16],rr;
int maxx(int a,int b)
{
	return a>b?a:b;
}
int main(void)
{
	int a,b;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		int ss[16][16];
		for(int p=0;p<16;p++) for(int q=0;q<16;q++) ss[p][q]=dp[p][q];
		for(int p=0;p<16;p++)
		{
			for(int q=0;q<16;q++)
			{
				if(p>=1) if(dp[p-1][q]!=-1) ss[p][q]=maxx(ss[p][q],dp[p-1][q]+a);
				if(q>=1) if(dp[p][q-1]!=-1) ss[p][q]=maxx(ss[p][q],dp[p][q-1]+b);
			}
		}
		for(int p=0;p<16;p++) for(int q=0;q<16;q++) dp[p][q]=ss[p][q];
		printf("asdf %d\n",dp[15][15]);
	}
	printf("%d",dp[15][15]);
}
