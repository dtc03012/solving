#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
double tot,dp[19][19],vis[19],f[19],s[19];
int aa[]={2,3,5,7,11,13,17};
int main(void)
{
	double a,b;
	cin >> a >> b;
	a/=100;
	b/=100;
	for(int e=0;e<=18;e++) dp[0][e]=1;
	for(int e=0;e<=18;e++) dp[e][e]=1;
	for(int e=0;e<7;e++) vis[aa[e]]=1;
	for(int e=1;e<=18;e++) for(int p=e+1;p<=18;p++) dp[e][p]=dp[e][p-1]+dp[e-1][p-1];
	for(int e=0;e<=18;e++)
	{
		if(vis[e]) continue;
		double kk=1;
		for(int p=0;p<18-e;p++) kk*=(1-a);
		for(int p=0;p<e;p++) kk*=a;
		kk*=dp[e][18];
		f[e]=kk;
	}
	for(int e=0;e<=18;e++)
	{
		if(vis[e]) continue;
		double kk=1;
		for(int p=0;p<18-e;p++) kk*=(1-b);
		for(int p=0;p<e;p++) kk*=b;
		kk*=dp[e][18];
		s[e]=kk;
	}
	for(int e=0;e<=18;e++)
	{
		if(vis[e]) continue;
		for(int p=0;p<=18;p++)
		{
			if(vis[p]) continue;
			tot+=f[e]*s[p];
		}
	}
	printf("%.6lf",1-tot);
}
