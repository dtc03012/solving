#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
long long int ff=0,fn=0,ss=0,sn=0,n,m;
int vis[1111111],vv[1111111];
int main(void)
{
	scanf("%lld%lld",&n,&m);
	ff=n*(n+1)/2;
	ss=n*(n+1)/2;
	for(int e=0;e<m;e++)
	{
		char a[2];
		long long int b;
		scanf("%s%d",a,&b);
		if(a[0]=='R')
		{
			if(vis[b]) printf("0\n");
			else
			{
				printf("%lld\n",b*n+ss-sn*b);
				ff-=b;
				fn++;
				vis[b]=1;
			}
		}
		if(a[0]=='C')
		{
			if(vv[b]) printf("0\n");
			else{
				printf("%lld\n",b*n+ff-fn*b);
				ss-=b;
				sn++;
				vv[b]=1;
			}
		}
	}
}
