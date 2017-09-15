#include <iostream>
#include <vector>
using namespace std;
vector<int> sosu;
int dd[2244],dp[2244][15];
int main(void)
{
	int n;
	cin >> n;
	for(int e=2;e<=1120;e++) if(dd[e]==0) for(int p=e*2;p<=1120;p+=e) dd[p]=1;
	for(int e=2;e<=1120;e++) if(dd[e]==0) sosu.push_back(e);
	for(int e=0;e<sosu.size();e++)
	{
		int kk[2244][15];
		for(int p=0;p<2244;p++) for(int q=0;q<15;q++) kk[p][q]=dp[p][q];
		int now=sosu[e];
		dp[now][1]=1;
		for(int q=2;q<15;q++)
		{
			for(int p=now+1;p<2244;p++)
			{
				dp[p][q]+=kk[p-now][q-1];
			}
		}
	}
	for(int e=0;e<n;e++)
	{
		int a,b;
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
}
