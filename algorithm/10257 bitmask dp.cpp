#include <iostream>
#include <string.h>
using namespace std;
int dp[1111][4][16][4][16],arr[12][1111],n,m,ma;
void bitmask(int now,int lltype,int llbit,int ltype,int lbit,int tot)
{
	if(now==m)
	{
		ma=min(ma,tot);
		return;
	}
	if(dp[now][lltype][llbit][ltype][lbit]<=tot) return;
	dp[now][lltype][llbit][ltype][lbit]=tot;
	int vis[11];
	memset(vis,0,sizeof(vis));
	for(int r=0;r<3;r++)
	{
		if(lltype==r||ltype==r)
		{
			for(int e=0;e<4;e++)
			{
				if(llbit&(1<<e)||lbit&(1<<e))
				{
					for(int q=e*3+r;q<(e+1)*3+r;q++)
					{
						if(q>=n) break;
						vis[q]=1;
					}
				}
			}
		}
	}
	int onbit=0,twbit=0,thbit=0;
	for(int e=0;e<n;e++) if(arr[e][now]&&!vis[e])
	{
		onbit=onbit|(1<<(e/3));
		if(e>0) twbit=twbit|(1<<((e-1)/3));
		if(e>1) thbit=thbit|(1<<((e-2)/3));
	}
	for(int e=onbit;e<16;e++)
	{
		int tt=0;
		for(int q=0;q<4;q++) if(e&(1<<q)) tt++;
		if(dp[now+1][ltype][lbit][0][e]>tot+tt) bitmask(now+1,ltype,lbit,0,e,tot+tt);
	}
	for(int e=twbit;e<8;e++)
	{
		int tt=0;
		for(int q=0;q<3;q++) if(e&(1<<q)) tt++;
		if(dp[now+1][ltype][lbit][1][e]>tot+tt) bitmask(now+1,ltype,lbit,1,e,tot+tt);
	}
	for(int e=thbit;e<8;e++)
	{
		int tt=0;
		for(int q=0;q<3;q++) if(e&(1<<q)) tt++;
		if(dp[now+1][ltype][lbit][2][e]>tot+tt) bitmask(now+1,ltype,lbit,2,e,tot+tt);
	}
}
int main(void)
{
	int t,c;
	cin >> t;
	while(t--)
	{
		ma=987654321;
		for(int e=0;e<1111;e++)
			for(int p=0;p<4;p++)
				for(int q=0;q<16;q++)
					for(int r=0;r<4;r++)
						for(int y=0;y<16;y++) dp[e][p][q][r][y]=987654321;
		memset(arr,0,sizeof(arr));
		cin >> n >> m >> c;
		for(int e=0;e<c;e++)
		{
			int a,b;
			cin >> a >> b;
			arr[a-1][b-1]=1;
		}
		bitmask(0,3,0,3,0,0);
		cout << ma << "\n";
	}
}
