#include <iostream>
#include <string.h>
using namespace std;
int a[222],n,d[222][222];
int q(int l,int r)
{
	if(r-l<2) return 0;
	if(d[l][r]) return d[l][r];
	if(r-l==2) return d[l][r]=a[l]+a[r]+a[(l+r)/2];
	int f=0;
	for(int e=l+1;e<r;e++) f=max(f,q(l,e)+q(e,r)+a[e]+a[l]+a[r]);
	return d[l][r]=f;
}
int main(void)
{
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int e=0;e<n;e++) scanf("%d",&a[e]);
		memset(d,0,sizeof(d));
		printf("%d\n",q(0,n-1));
	}
}
