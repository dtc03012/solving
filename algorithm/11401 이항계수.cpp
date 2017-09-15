#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
long long int dp[4444444],sosu[4444444],mod;
long long int recur(long long int a,long long int b,long long int c)
{
	if(b==1) return a;
	long long int kk=recur(a,b/2,c);
	if(b%2) return (((kk*kk)%c)*a)%c;
	else return (kk*kk)%c;
}
int main(void)
{
	long long int a=1,b=1,c=1,n,m;
	for(int e=2;e<4444444;e++) if(sosu[e]==0) for(int p=e*2;p<4444444;p+=e) sosu[p]=1;
	cin >> n >> m >> mod;
	vector<long long int> k,q;
	for(int e=2;e<4444444;e++) if(sosu[e]==0) k.push_back(e);
	for(int e=0;e<k.size();e++)
	{
		if(mod%k[e]==0) q.push_back(k[e]); 
		while(mod%k[e]==0) mod/=k[e];
		if(mod==1) break;
	}
	long long int res=1;
	for(int ee=0;ee<q.size();ee++)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		dp[1]=1;
		for(int e=2;e<4444444;e++) dp[e]=(dp[e-1]*e)%q[ee];
		while(n&&m)
		{
			long long int nn=n%q[ee];
			long long int mm=m%q[ee];
			if(mm>nn)
			{
				res=0;
				break;
			}
			res=(res*dp[nn])%q[ee];
			res=(res*recur((dp[nn-mm]*dp[mm])%q[ee],q[ee]-2,q[ee]))%q[ee];
			n/=q[ee];
			m/=q[ee];
		}
	}
	cout << res;
}
