#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long int arr[111111][2],n,check[111111],check2[111111];
bool ccal(long long int f,long long int f_a,long long int f_b,long long int s,long long int s_a,long long int s_b,long long int now)
{
	memset(check,0,sizeof(check));
	memset(check2,0,sizeof(check2));
	long long int lleft=2e9+10,rright=-2e9-10,uup=-2e9-10,ddown=2e9+10;
	for(int e=0;e<n;e++)
	{
		if(arr[e][0]>=f+f_a&&arr[e][0]<=f+f_b)
		{
			if(arr[e][1]>=s+s_a&&arr[e][1]<=s+s_b)
			{
				check[e]=1;
			}
		}
	}
	for(int e=0;e<n;e++)
	{
		if(check[e]==0)
		{
			lleft=min(lleft,arr[e][0]);
			rright=max(rright,arr[e][0]);
			uup=max(uup,arr[e][1]);
			ddown=min(ddown,arr[e][1]);
		}
	}
	for(int e=0;e<n;e++) check2[e]=check[e];
	for(int e=0;e<n;e++)
	{
		if(check[e]==0)
		{
			if(arr[e][0]>=lleft&&arr[e][0]<=lleft+now)
			{
				if(arr[e][1]>=uup-now&&arr[e][1]<=uup)
				{
					check[e]=1;
				}
			}			
		}
	}
	for(int e=0;e<n;e++)
	{
		if(check[e]==0)
		{
			if(arr[e][0]>=rright-now&&arr[e][0]<=rright)
			{
				if(arr[e][1]>=ddown&&arr[e][1]<=ddown+now)
				{
					check[e]=1;
				}
			}			
		}
	}
	int ppp=0;
	for(int e=0;e<n;e++) if(check[e]==0) ppp++;
	if(ppp==0) return true;
	ppp=0;
	for(int e=0;e<n;e++)
	{
		if(check2[e]==0)
		{
			if(arr[e][0]>=rright-now&&arr[e][0]<=rright)
			{
				if(arr[e][1]>=uup-now&&arr[e][1]<=uup)
				{
					check2[e]=1;
				}
			}
		}
	}
	for(int e=0;e<n;e++)
	{
		if(check2[e]==0)
		{
			if(arr[e][0]>=lleft&&arr[e][0]<=lleft+now)
			{
				if(arr[e][1]>=ddown&&arr[e][1]<=ddown+now)
				{
					check2[e]=1;
				}
			}
		}
	}
	for(int e=0;e<n;e++) if(check2[e]==0) ppp++;
	if(ppp==0) return true;
	return false;
}
bool cal(long long int now)
{
	long long int left=2e9+1,right=-2e9-1,up=-2e9-1,down=2e9+1;
	for(int e=0;e<n;e++)
	{
		left=min(left,arr[e][0]);
		right=max(right,arr[e][0]);
		up=max(up,arr[e][1]);
		down=min(down,arr[e][1]);
	}
	int ppp=0;
	if(ccal(left,0,now,up,-now,0,now)) ppp++;
	if(ccal(left,0,now,down,0,now,now)) ppp++;
	if(ccal(right,-now,0,up,-now,0,now)) ppp++;
	if(ccal(right,-now,0,down,0,now,now)) ppp++;
	if(ppp) return true;
	return false;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(arr,0,sizeof(arr));
		scanf("%d",&n);
		for(int e=0;e<n;e++) scanf("%lld%lld",&arr[e][0],&arr[e][1]);
		long long int low=0,high=2e9+10,mid;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(cal(mid))
			{
				high=mid-1;
			}	
			else{
				low=mid+1;
			}
		}	
		printf("%lld\n",low);
	}
}
