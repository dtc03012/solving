#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int dp[111][11],arr[111],parent[111][11],hap[111][111],nuzuk[111][111];
vector<int> s;
int main(void)
{
	memset(parent,-1,sizeof(parent));
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> arr[e];
	for(int e=0;e<n;e++)
	{
		int now=arr[e];
		for(int p=e+1;p<n;p++)
		{
			hap[e][p]=now*arr[p];
			nuzuk[e][p]=nuzuk[e][p-1]+hap[e][p];
			now+=arr[p];
		}
	}
	for(int e=1;e<n;e++) dp[e][0]=nuzuk[0][e];
	for(int e=1;e<=m;e++) for(int p=0;p<111;p++) dp[p][e]=987654321;
	for(int e=1;e<=m;e++)
	{
		for(int p=e;p<n;p++)
		{
			for(int q=e;q<=p;q++)
			{
				if(dp[p][e]>=dp[q-1][e-1]+nuzuk[q][p])
				{
					dp[p][e]=dp[q-1][e-1]+nuzuk[q][p];
					parent[p][e]=q;
				}
			}
		}
	}
	printf("%d\n",dp[n-1][m]);
	int kk=parent[n-1][m];
	while(kk!=-1)
	{
		m--;
		s.push_back(kk);
		kk=parent[kk-1][m];
	}
	for(int e=s.size()-1;e>=0;e--) printf("%d\n",s[e]);
}
