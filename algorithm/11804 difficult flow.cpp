#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define M 52
#define E 252
#define S 620
using namespace std;
int n,m,d;
vector<int> arr[S];
int cap[S][S],flow[S][S],dist[S][S];
void add(int f,int s,int ca,int wei){
   arr[f].push_back(s);
   arr[s].push_back(f);
   cap[f][s]=ca;
   dist[f][s]=wei;
   dist[s][f]=-wei;
}
int flows(int capacity){
   int tot=0;
   memset(flow,0,sizeof(flow));
   for(int e=1;e<=n;e++){
      cap[0][e]=capacity;
      cap[M+E*2+e][M*2+E*2]=capacity;
   }
   while(1){
      vector<int> parent(S,-1),di(S,987654321),inque(S,0);
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
      if(parent[M*2+E*2]==-1) break;
      int amount=987654321;
      for(int e=M*2+E*2;e!=0;e=parent[e]) amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
      for(int e=M*2+E*2;e!=0;e=parent[e]){
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
      for(int e=0;e<S;e++) arr[e].clear();
      memset(cap,0,sizeof(cap));
      memset(flow,0,sizeof(flow));
      memset(dist,0,sizeof(dist));
      scanf("%d%d%d",&n,&m,&d);
      for(int e=1;e<=n;e++) add(0,e,0,0);
      for(int e=1;e<=m;e++){
         int p,st,en,k;
         scanf("%d%d%d%d",&p,&st,&en,&k);
         add(st,e+M,987654321,0);
         add(e+M,e+M+E,p,0);
         add(M+E+e,M+E*2+en,987654321,-k);
      }
      for(int e=1;e<=n;e++) add(M+E*2+e,M*2+E*2,0,0);
      int f=0,s=5000000,left,right;
      for(int e=0;e<100;e++){
         left=(2*f+s)/3;
         right=(f+2*s)/3;
         if(flows(left)>=flows(right)){
            s=right;
         }else{
            f=left;
         }
      }
      flows(10);
      
      cout << dist[M+E+1][M+E*2+2]<<" " << flow[M+E*2+2][M*2+E*2] << " " <<endl;
      printf("Case %d: %d\n",ee,flows(right));
   }
   return 0;
}
