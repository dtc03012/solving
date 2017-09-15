#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct inf
{
	int x,sy,ey,type;
};
bool tmr(inf a,inf b)
{
	if(a.x<b.x) return true;
	if(a.x>b.x) return false;
	if(a.sy<b.sy) return true;
	return false;
}
vector<inf> arr;
int seg[33333*4],start=1,seg2[33333*4];
int main(void)
{
	int n;
	scanf("%d",&n);
	while(30000>start) start*=2;
	for(int e=0;e<n;e++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		inf k;
		k.x=a;
		k.sy=b;
		k.ey=d;
		k.type=0;
		arr.push_back(k);
		k.x=c;
		k.type=1;
		arr.push_back(k);
	}
	sort(arr.begin(),arr.end(),tmr);
	int lx=0,result=0;
	for(int e=0;e<arr.size();e++)
	{
		int tot=0,left=start,right=start+30000;
		while(left<=right)
		{
			if(left%2)
			{
				tot+=seg2[left];
				left++;
			}
			if(!(right%2))
			{
				tot+=seg2[right];
				right--;
			}
			left/=2;
			right/=2;
		}
		result+=(arr[e].x-lx)*tot;
		if(arr[e].type==0)
		{
			for(int p=arr[e].sy;p<arr[e].ey;p++) seg[p+start]++;
		}
		else
		{
			for(int p=arr[e].sy;p<arr[e].ey;p++) seg[p+start]--;
		}
		for(int e=start;e<start+30000;e++) seg2[e]=(seg[e]>0?1:0);
		for(int e=start-1;e>0;e--) seg2[e]=seg2[e*2]+seg2[e*2+1];
		lx=arr[e].x;
	}
	printf("%d",result);
}
