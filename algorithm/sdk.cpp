#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int aa[1111111];
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(aa,0,sizeof(aa));
		int n;
		scanf("%d",&n);
		priority_queue<pair<int,int> > q;
		for(int e=0;e<n;e++)
		{
			int k;
			scanf("%d",&k);
			if(e==0) aa[e]=k;
			else aa[e]=aa[e-1]+k;
			q.push(make_pair(k,e));
		}
		long long int tot=0,wh=-1;
		while(!q.empty())
		{
			int now=q.top().first,nn=q.top().second;q.pop();
			if(nn>wh)
			{
				tot+=(nn-wh)*now;
				tot-=aa[nn];
				if(wh!=-1) tot+=aa[wh];
				wh=nn;
			}
		}
		printf("%lld\n",tot);
	}
}
