#include <stdio.h>
int arr[33333],n;
int main(void)
{
	for(int e=0;e<200;e++)
	{
		for(int p=e;p<200;p++)
		{
			for(int q=p;q<200;q++)
			{
				for(int r=q;r<200;r++)
				{
					if(e*e+p*p+q*q+r*r<33333)
					{
						arr[e*e+p*p+q*q+r*r]++;
					}		
				}
			}
		}
	}
	while(scanf("%d",&n)==1)
	{
		printf("%d\n",arr[n]);
	}
}
