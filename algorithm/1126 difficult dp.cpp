#include <stdio.h>
#include <string.h>
int abs(int n)
{
	return n>0?n:-n;
}
int max(int n,int m)
{
	return n>m?n:m;
}
int n,arr[55],mx;
int a[55][555555];
int main(void)
{
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);	
	for(int e=0;e<n;e++) a[e][arr[e]]=arr[e];
	for(int e=1;e<n;e++)
	{
		for(int p=0;p<555555;p++)
		{
			if(a[e-1][p])
			{
				a[e][p+arr[e]]=max(a[e][p+arr[e]],a[e-1][p]+arr[e]);
				if(arr[e]>p) a[e][abs(p-arr[e])]=max(a[e][abs(p-arr[e])],a[e-1][p]+abs(p-arr[e]));
				else a[e][abs(p-arr[e])]=max(a[e][abs(p-arr[e])],a[e-1][p]);
				a[e][p]=max(a[e][p],a[e-1][p]);
			}
		}
	}
	if(a[n-1][0]==0) printf("-1");
	else printf("%d",a[n-1][0]);
}
