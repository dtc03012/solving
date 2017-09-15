#include <iostream>
#include <queue>

using namespace std;
bool vis[11][1111111];
int ma=-1;
int main(void)
{
	int a,b;
	cin >> a >> b;
	queue<pair<int,int> > q;
	q.push(make_pair(a,0));
	vis[0][a]=true;
	while(!q.empty())
	{
		int now=q.front().first,num=q.front().second;q.pop();
		if(num==b)
		{
			ma=max(ma,now);
			continue;
		}
		vector<int> rr;
		while(now!=0)
		{
			rr.push_back(now%10);
			now/=10;
		}
		for(int e=0;e<rr.size();e++)
		{
			for(int qq=e+1;qq<rr.size();qq++)
			{
				int tmp=rr[e];
				rr[e]=rr[qq];
				rr[qq]=tmp;
				int dd=0;
				for(int t=rr.size()-1;t>=0;t--) dd=dd*10+rr[t];
				if(vis[num+1][dd]==0&&rr[rr.size()-1]!=0)
				{
					vis[num+1][dd]=1;
					q.push(make_pair(dd,num+1));
				}
				tmp=rr[e];
				rr[e]=rr[qq];
				rr[qq]=tmp;
			}
		}
	}
	cout << ma;
}
