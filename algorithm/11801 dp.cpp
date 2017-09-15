#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
long long int dp[5555],arr[5555];
int main(void){
	int t;
	scanf("%d",&t);
	dp[0]=1;
	for(int e=1;e<=t;e++){
		memset(dp,0,sizeof(dp));
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		for(int r=0;r<b;r++){
			long long int n,m,kk[5555];
			scanf("%lld%lld",&n,&m);
			for(int e=0;e<=a;e++) kk[e]=dp[e];
			for(int e=n;e<=a;e++){
				
			}
		}
		long long int tot=0;
		for(int ee=1;ee<5555;ee++) tot+=dp[ee][a];
		printf("Case %d: %lld\n",e,tot);
	}
}

