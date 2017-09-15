#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int fail[5555],mx=-1;
int main(void)
{
	string tmp;
	cin >> tmp;
	tmp=" "+tmp;
	for(int p=1;p<tmp.size();p++)
	{
		string kk;
		for(int e=p-1;e<tmp.size();e++) kk+=tmp[e];
		memset(fail,0,sizeof(fail));
		for(int e=2;e<kk.size();e++)
		{
			int v=fail[e-1];
			while(1)
			{
				if(kk[e]==kk[v+1])
				{
					fail[e]=v+1;
					break;
				}
				if(v==0) break;
				v=fail[v];
			}
			mx=max(mx,fail[e]);
		}
	}
	cout << mx;
}
