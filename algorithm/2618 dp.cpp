#include <iostream>
#include <vector>
using namespace std;
pair<int,int> arr[1111];
struct inf{
	int value,parent;
	pair<int,int> f[2];
};
int abs(int a)
{
	return a>0?a:-a;
}
inf dp[1111][2];
int main(void)
{
	int m,n;
	cin >> m >> n;
	dp[0][0].value=0;
	dp[0][0].parent=-1;
	dp[0][0].f[0]=make_pair(1,1);
	dp[0][0].f[1]=make_pair(m,m);
	dp[0][1]=dp[0][0];
	for(int e=1;e<=n;e++) cin >> arr[e].first >> arr[e].second;
	for(int e=1;e<=n;e++)
	{
		for(int p=0;p<2;p++)
		{
			int mm=987654321;
			for(int q=e-1;q>=0;q--)
			{
				int tot=abs(dp[q][p].f[p].first-arr[e].first)+abs(dp[q][p].f[p].second-arr[e].second)+dp[q][p].value;
				int ff=dp[q][p].f[(p+1)%2].first,ss=dp[q][p].f[(p+1)%2].second;
				for(int r=q+1;r<=e-1;r++)
				{
					tot+=abs(arr[r].first-ff)+abs(arr[r].second-ss);
					ff=arr[r].first;
					ss=arr[r].second;
				}
				if(mm>tot)
				{
					mm=tot;
					dp[e][p].value=tot;
					dp[e][p].parent=q;
					dp[e][p].f[p]=make_pair(arr[e].first,arr[e].second);
					dp[e][p].f[(p+1)%2]=make_pair(ff,ss);
				}
			}
		}
	}
	vector<int> kk;
	cout << min(dp[n][0].value,dp[n][1].value)<<endl;
	if(dp[n][0].value<dp[n][1].value)
	{
		int nn=dp[n][0].parent,now=n;
		while(nn!=-1)
		{
			kk.push_back(1);
			for(int p=now-1;p>nn;p--) kk.push_back(2);
			now=nn;
			nn=dp[now][0].parent;
		}
	}
	else 
	{
		int nn=dp[n][1].parent,now=n;
		while(nn!=-1)
		{
			kk.push_back(2);
			for(int p=now-1;p>nn;p--) kk.push_back(1);
			now=nn;
			nn=dp[now][1].parent;
		}
	}
	for(int e=kk.size()-1;e>=0;e--) cout << kk[e] << "\n";
}
