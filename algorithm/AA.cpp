#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
struct inf{
	int y,num,t;
};
int vis[1111],vis2[1111],n,st,pn,pt,l,dp[1111];
vector<inf> arr[1111];
void dfs(int now,int num1,int num2){
	if(num1>pt){
		return;
	}
 	if(vis[now]==1)
	{
		for(int e=num1;e<=pt;e++) vis2[e]+=num2;
		return;
	}
	for(int e=0;e<arr[now].size();e++){
		int next=arr[now][e].y;
		if(dp[next]==0){
			dp[next]=1;
			dfs(next,num1+arr[now][e].t,min(num2,arr[now][e].num));
			dp[next]=0;
		}
		
	}
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int e=0;e<1111;e++) arr[e].clear();
		memset(vis2,0,sizeof(vis2));
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d%d",&n,&st,&pn,&pt,&l);
		for(int e=0;e<l;e++){
			int k;
			scanf("%d",&k);
			vis[k]=1;
		}
		int m;
		scanf("%d",&m);
		for(int e=0;e<m;e++){
			int ttt;
			inf rr;
			scanf("%d%d%d%d",&ttt,&rr.y,&rr.num,&rr.t);
			arr[ttt].push_back(rr);
			int tmp=rr.y;
			rr.y=ttt;
			arr[tmp].push_back(rr);
		}
		dp[st]=1;
		dfs(st,0,pn);
		int tt=0;
		for(int e=0;e<=pt;e++) tt+=vis2[e];
		printf("%d\n",min(tt,pn));
	}
}
