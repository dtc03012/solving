#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
vector<int> maps[888];
int cap[888][888],flow[888][888];
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int e=1;e<=n;e++)
    {
        maps[e].push_back(e+401);
        maps[e+401].push_back(e);
        cap[e][e+401]=1;
        cap[e+401][e]=1;
    }
    for(int e=0;e<m;e++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        maps[a+401].push_back(b);
        maps[b].push_back(a+401);
        cap[a+401][b]=1;
        cap[b][a+401]=1;
    }
    int result=0;
    while(1)
    {
        vector<int> parent(888,-1);
        queue<int> q;
        q.push(402);
        while(!q.empty())
        {
            int now=q.front();q.pop();
            for(int e=0;e<maps[now].size();e++)
            {
                int next=maps[now][e];
                if(cap[now][next]-flow[now][next]>0&&parent[next]==-1)
                {
                    parent[next]=now;
                    q.push(next);
                }
            }
        }
        if(parent[2]==-1) break;
        int amount=987654321;
        for(int e=2;e!=402;e=parent[e]) amount=min(amount,cap[parent[e]][e]-flow[parent[e]][e]);
        for(int e=2;e!=402;e=parent[e])
        {
            flow[parent[e]][e]+=amount;
            flow[e][parent[e]]-=amount;
        }
        result+=amount;
    }
    printf("%d",result);
}
