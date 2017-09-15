#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
int dp[161051];
char nn[6];
int nnow(){
	int pp=0,qq=1,size=strlen(nn);
	for(int e=size-1;e>=0;e--){
		pp+=qq*(nn[e]-'0'+1);
		qq*=11;
	}
	return pp;
}
void push(int len,int now,int val,int ll){
	if(len==-1){
		dp[now]=1;
		return;
	}
	if(nn[len]-'0'>=val){
		push(len-1,now+(nn[len]-'0'-val+1)*ll,val,ll*11);
	}
	if(nn[len]-'0'<=9-val){
		push(len-1,now+(nn[len]-'0'+val+1)*ll,val,ll*11);
	}
}
int main(void){
	int t;
	scanf("%d",&t);
	for(int ee=1;ee<=t;ee++){
		memset(dp,0,sizeof(dp));
		int m,ttt=0;
		scanf("%d",&m);
		for(int e=0;e<m;e++){
			scanf("%s",nn);
			int now=nnow();
			if(dp[now]==0) {
				ttt++;
				for(int p=1;p<=9;p++) push(strlen(nn)-1,0,p,1);
			}
			dp[now]=1;
		}
		printf("Case %d: %d\n",ee,ttt);
	}
}
