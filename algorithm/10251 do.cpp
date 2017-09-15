#include <stdio.h>
#include <iostream>
#include <String.h>
using namespace std;
int a[101][101][222][2],b[101][101][2];
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int e=0;e<101;e++) for(int p=0;p<101;p++) for(int r=0;r<222;r++) for(int q=0;q<2;q++) a[e][p][r][q]=987654321;
		int n,m,l,g;
		scanf("%d%d%d%d",&n,&m,&l,&g);
		for(int e=0;e<n;e++)
		{
			for(int p=0;p<m-1;p++)
			{
				int k;
				scanf("%d",&k);
				b[e][p][0]=k;
			}
		}
		for(int e=0;e<n-1;e++)
		{
			for(int p=0;p<m;p++)
			{
				int k;
				scanf("%d",&k);
				b[e][p][1]=k;
			}
		}
		a[0][0][0][0]=0;
		a[0][0][0][1]=0;
		for(int e=0;e<n;e++)
		{
			for(int p=0;p<m;p++)
			{
				if(e)
				{
					for(int q=0;q<2;q++)
					{
						for(int r=0;r<222;r++)
						{
							if(a[e-1][p][r][q]!=987654321)
							{
								if(q==1)
								{
									a[e][p][r][1]=min(a[e][p][r][1],a[e-1][p][r][q]+b[e-1][p][1]);
								}
								else
								{
									a[e][p][r+1][1]=min(a[e][p][r+1][1],a[e-1][p][r][q]+b[e-1][p][1]);
								}
							}
						}
					}
				}
				if(p)
				{
					for(int q=0;q<2;q++)
					{
						for(int r=0;r<222;r++)
						{
							if(a[e][p-1][r][q]!=987654321)
							{
								if(q==0)
								{
									a[e][p][r][0]=min(a[e][p][r][0],a[e][p-1][r][q]+b[e][p-1][0]);
								}
								else
								{
									a[e][p][r+1][0]=min(a[e][p][r+1][0],a[e][p-1][r][q]+b[e][p-1][0]);
								}
							}
						}
					}
				}
			}
		}
		int pp=0;
		for(int e=0;e<222;e++) 
		{
			if(a[n-1][m-1][e][0]<=g||a[n-1][m-1][e][1]<=g)
			{
				pp++;
				printf("%d\n",e+(n+m-2)*l);
				break;	
			} 
		}
		if(pp==0)
		{
			printf("-1\n");
		}
	}
}
