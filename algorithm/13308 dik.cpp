#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
vector<pair<long long int,long long int> > arr[2555];
long long int dist[2555],n,m,val[2555][2555];
int main(void)
{
	scanf("%lld%lld",&n,&m);
	for(int e=1;e<=n;e++) scanf("%lld",&dist[e]);
	for(int e=0;e<m;e++)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		arr[a].push_back(make_pair(b,c));
		arr[b].push_back(make_pair(a,c));	
	}
	for(int e=0;e<2555;e++) for(int p=0;p<2555;p++) val[e][p]=1e15;
	val[1][dist[1]]=0;
	priority_queue<pair<long long int,pair<long long int,long long int> > > q;
	q.push(make_pair(0,make_pair(1,dist[1])));
	while(!q.empty())
	{
		long long int diist=-q.top().first,now=q.top().second.first,gz=q.top().second.second;q.pop();
		for(int e=0;e<arr[now].size();e++)
		{
			long long int next=arr[now][e].first,ddist=diist+gz*arr[now][e].second,rr=gz;
			rr=min(dist[next],rr);
			if(val[next][rr]>ddist)
			{
				val[next][rr]=ddist;
				q.push(make_pair(-ddist,make_pair(next,rr)));
			}
		}
	}
	long long int mm=1e15;
	for(int e=0;e<2555;e++) mm=min(mm,val[n][e]);
	printf("%lld",mm);
}
