#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int fail[1111111],dp[1111111];
int main(void)
{
	string a,b;
	getline(cin,a);
	a=" "+a;
	getline(cin,b);
	b=" "+b;
	for(int e=2;e<=b.size();e++)
	{
		int v=fail[e-1];
		while(1)
		{
			if(b[e]==b[v+1])
			{
				fail[e]=v+1;
				break;
			}
			if(v==0) break;
			v=fail[v];
		}
	}
	for(int e=1;e<=a.size();e++)
	{
		int v=dp[e-1];
		while(1)
		{
			if(a[e]==b[v+1])
			{
				dp[e]=v+1;
				break;
			}
			if(v==0) break;
			v=fail[v];
		}
	}
	int kk=0;
	for(int e=1;e<=a.size();e++) if(dp[e]==b.size()-1) kk++;
	cout << kk << endl;
	for(int e=1;e<=a.size();e++) if(dp[e]==b.size()-1)
	{
		cout << e-b.size()+2 << endl;
	}
}
