#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define M 51
#define E 251
using namespace std;
int n,m,d;
vector<int> arr[444];
int cap[444][444],flow[444][444],dist[444][444],what[444];
int flows(int capacity){
	int tot=0;
	memset(flow,0,sizeof(flow));
	for(int e=1;e<=n;e++) cap[e][what[e]]=capacity;
	while(1){
		vector<int> parent(444,-1),di(444,987654321),inque(444,0);
		di[0]=0;
		queue<int> q;
		q.push(0);
		inque[0]=1;
		while(!q.empty()){
			int now=q.front();q.pop();
			inque[now]=0;
			for(int e=0;e<arr[now].size();e++){
				int next=arr[now][e];
				if(cap[now][next]-flow[now][next]>0&&di[next]>di[now]+dist[now][next]){
					if(inque[next]==0){
						inque[next]=1;
						q.push(next);
					}
					di[next]=di[now]+dist[now][next];
					parent[next]=now;
				}
			}
		}
		if(parent[M+E+1]==-1) break;
		int amount=987654321;
		for(int e=M+E+1;e!=0;e=parent[e]) amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
		for(int e=M+E+1;e!=0;e=parent[e]){
			tot+=dist[parent[e]][e]*amount;
			flow[parent[e]][e]+=amount;
			flow[e][parent[e]]-=amount;
		}
	}
	return -tot-capacity*d;
}
int main(void){
	int t;
	scanf("%d",&t);
	for(int ee=1;ee<=t;ee++){
		for(int e=0;e<444;e++) arr[e].clear();
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(dist,0,sizeof(dist));
		memset(what,0,sizeof(what));
		scanf("%d%d%d",&n,&m,&d);
		for(int e=1;e<=m;e++){
			int p,st,en,k;
			scanf("%d%d%d%d",&p,&st,&en,&k);
			what[e]=st+M;
			arr[e].push_back(st+M);
			arr[st+M].push_back(e);
			dist[e][st+M]=-k;
			dist[st+M][e]=k;
			arr[0].push_back(e);
			arr[e].push_back(0);
			arr[st+M].push_back(M+E+1);
			arr[M+E+1].push_back(st+M);
			cap[st+M][M+E+1]=987654321;
			cap[0][e]=p;
		}
		int f=0,s=5000000,left,right;
		for(int e=0;e<100;e++){
			left=(2*f+s)/3;
			right=(f+2*s)/3;
			cout << left << " " <<right << endl;
			if(flows(left)>=flows(right)){
				s=right;
			}else{
				f=left;
			}
		}
		printf("Case %d: %d\n",ee,flows(right));
	}
	return 0;
}
