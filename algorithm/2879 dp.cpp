#include <iostream>
#include <vector>
#define m 987654321
using namespace std;
int f[1111],n,aa[1111][1111],tot;
int abs(int n)
{
	return n>0?n:-n;
}
int main(void)
{
	cin >> n;
	for(int e=0;e<n;e++) cin >> f[e];
	for(int e=0;e<n;e++)
	{
		int k;
		cin >> k;
		f[e]=k-f[e];
	}
	while(1)
	{
		int kk=-1,wh,ma=m,mi=-m,poss=0;
		for(int e=0;e<n;e++) if(f[e]) poss++;
		if(poss==0) break;
		for(int e=0;e<=n;e++)
		{
			if(f[e]>0)
			{
				ma=min(ma,f[e]);
				if(kk==-1) wh=e;
				if(kk==1)
				{
					tot+=abs(mi);
					for(int p=wh;p<e;p++) f[p]+=abs(mi);
					mi=-m;
					wh=e;
				}
				kk=0;
			}
			if(f[e]==0)
			{
				if(kk==0)
				{
					tot+=abs(ma);
					for(int p=wh;p<e;p++) f[p]-=ma;
					ma=m;
				}
				if(kk==1)
				{
					tot+=abs(mi);
					for(int p=wh;p<e;p++) f[p]+=abs(mi);
					mi=-m;
				}
				kk=-1;
			}
			if(f[e]<0)
			{
				mi=max(mi,f[e]);
				if(kk==-1) wh=e;
				if(kk==0)
				{
					tot+=abs(ma);
					for(int p=wh;p<e;p++) f[p]-=abs(ma);
					ma=m;
					wh=e;
				}
				kk=1;
			}
		}
	}
	cout << tot;
}
