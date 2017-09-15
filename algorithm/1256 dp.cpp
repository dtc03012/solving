#include <iostream>
#include <string>
#define M 1000000001
using namespace std;
int dp[222][112][112],n,m,k;
int main(void)
{
	for(int e=1;e<=100;e++)
	{
		for(int p=0;p<=100;p++)
		{
			dp[e][p][0]=1;
			for(int q=1;q<=e;q++) dp[e][p][q]=min(M,(p==0?0:dp[q][p-1][q])+dp[e][p][q-1]);
		}
	}
	string tmp;
	cin >> n >> m >> k;
	if(dp[n][m][n]<k)
	{
		cout << "-1";
		return 0;
	}
	while(n!=0&&m!=0)
	{
		for(int e=0;e<=n;e++)
		{
			if(dp[n][m][e]>=k)
			{
				for(int p=0;p<n-e;p++) tmp+="a";
				k-=dp[n][m][e-1];
				tmp+="z";	
				n=e;
				m=m-1;
				break;
			}
		}
	}
	for(int e=0;e<n;e++) tmp+="a";
	for(int e=0;e<m;e++) tmp+="z";
	cout << tmp;
}
