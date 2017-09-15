#include <iostream>
#include <string>
using namespace std;
int aa[2018][2018*2],vis[2018*2018],now[2018*2018];
int main(void)
{
	int n,m,q=1;
	cin >> n >> m;
	if(n<=m)
	{
		cout << "-1";
		return 0;
	}
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			aa[e][p]=q;
			vis[q]=e;
			q++;
		}
	}
	q=1;
	int wh=n-1;
	while(q<=n*m)
	{
		if(now[wh]>=m) {
			wh--;
			if(wh<0) wh=n-1;
			continue;
		}
		if(wh==vis[q]){
			wh--;
			if(wh<0) wh=n-1;
			continue;
		}
		aa[wh][now[wh]+m]=q;
		now[wh]++;
		q++;
		wh--;
		if(wh<0) wh=n-1;
	}
	for(int e=0;e<n;e++)
	
	{
		for(int p=0;p<2*m;p++) cout << aa[e][p] << " ";
		cout << "\n";
	}
}
