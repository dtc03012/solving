#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,pair<int,int> > arr[222222];
bool tmr(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b)
{
	if(a.first<b.first) return true;
	if(a.first>b.first) return false;
	if(a.second.second<b.second.second) return true;
	return false;
}
int dp[222222],rr=2e9+1,vis[222222];
int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int e=0;e<a;e++)
	{
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		arr[e]=make_pair(q-p+1,make_pair(p,r));
	}
	int posss=0;
	sort(arr,arr+a,tmr);
	for(int e=0;e<a;e++) dp[e]=arr[e].first;
	for(int e=0;e<a;e++)
	{
		if(vis[e])
		{
			posss++;
			continue;
		}
		if(e>0) if(dp[e]==dp[e-1]) if(posss) continue;
		posss=0;
		int left=0,right=a-1,mid,wh=-1;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(dp[mid]>b-dp[e])
			{
				right=mid-1;
			}
			if(dp[mid]==b-dp[e])
			{
				int rrr=2e9+1,www=-1;
				for(int p=mid;p>=0;p--)
				{
					if(p==e) continue;
					if(dp[p]==b-dp[e])
					{
						int fff=arr[e].second.first,ffs=arr[e].second.first+dp[e]-1;
						int sss=arr[p].second.first,ssr=arr[p].second.first+dp[p]-1;
						int poss=0;
						if(sss>ffs&&ssr>ffs) poss++;
						if(sss<fff&&ssr<fff) poss++;
						if(poss)
						{
							rrr=arr[e].second.second+arr[p].second.second;
							posss++;
							www=p;
						}
					}
					else
					{
						if(www!=-1) 
						{
							vis[www]=1;
							vis[e]=1;
						}
						break;
					}
				}
				rr=min(rrr,rr);
				break;
			}
			if(dp[mid]<b-dp[e])
			{
				left=mid+1;
			}
		}
	}
	if(rr==2e9+1) cout << "-1";
	else cout << rr;
}
