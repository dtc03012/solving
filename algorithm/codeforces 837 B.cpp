#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string tmp[111],kk="RGB";
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> tmp[e];
	int pp=0,wh=-1;
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m-1;p++) if(tmp[e][p]!=tmp[e][p+1]) pp++;
	}
	if(pp==0) wh=0;
	pp=0;
	for(int e=0;e<m;e++)
	{
		for(int p=0;p<n-1;p++) if(tmp[p][e]!=tmp[p+1][e]) pp++;
	}
	if(pp==0) wh=1;
	if(wh==-1)
	{
		cout << "NO";
		return 0;
	}
	if(wh==0)
	{
		int a[26];
		memset(a,0,sizeof(a));
		a[tmp[0][0]-'A']++;
		for(int e=1;e<n;e++)
		{
			if(tmp[e][0]!=tmp[e-1][0])
			{
				if(a[tmp[e][0]-'A'])
				{
					cout << "NO";
					return 0;
				}
			}
			a[tmp[e][0]-'A']++;
		}
		int rr=0;
		for(int e=0;e<2;e++)
		{
			if(a[kk[e]-'A']!=a[kk[e+1]-'A']) rr++;
		}
		if(rr)
		{
			cout << "NO";
			return 0;
		}
		else
		{
			cout << "YES";
		}
	}
	if(wh==1)
	{
		int a[26];
		memset(a,0,sizeof(a));
		a[tmp[0][0]-'A']++;
		for(int e=1;e<m;e++)
		{
			if(tmp[0][e]!=tmp[0][e-1])
			{
				if(a[tmp[0][e]-'A'])
				{
					cout << "NO";
					return 0;
				}
			}
			a[tmp[0][e]-'A']++;
		}
		int rr=0;
		for(int e=0;e<2;e++)
		{
			if(a[kk[e]-'A']!=a[kk[e+1]-'A']) rr++;
		}
		if(rr)
		{
			cout << "NO";
			return 0;
		}
		else
		{
			cout << "YES";
		}
	}
}
