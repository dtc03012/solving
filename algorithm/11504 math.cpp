#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c=0,d=0,tt=0,aa[111];
		scanf("%d%d",&a,&b);
		for(int e=0;e<b;e++)
		{
			int k;
			scanf("%d",&k);
			c=c*10+k;
		}
		for(int e=0;e<b;e++)
		{
			int k;
			scanf("%d",&k);
			d=d*10+k;
		}
		for(int e=0;e<a;e++) scanf("%d",&aa[e]);
		for(int e=0;e<a;e++)
		{
			int k=0;
			for(int p=e;p<e+b;p++)
			{
				k=k*10+aa[p%a];
			}
			if(k>=c&&k<=d) tt++;
		}
		printf("%d\n",tt);
	}
}
