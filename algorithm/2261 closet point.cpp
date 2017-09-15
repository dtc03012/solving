#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
pair<int,int> arr[111111];
int minn=111111,mann=-111111,n,kk[111111];
bool tmr(pair<int,int> a,pair<int,int> b)
{
	if(a.first<b.first) return true;
	if(a.first>b.first) return false;
	if(a.second<b.second) return true;
	return false;
}
int cal(int i,int j)
{
	return (arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
}
int recur(int left,int right)
{
	if(right<=left) return 987654321;
	int mid=(left+right)/2;
	int a=recur(left,mid),b=recur(mid+1,right),cc=min(a,b);
	if(right-left==1)
	{
		return cal(left,right);
	}
	int rmin=987654321;
	for(int e=mid-1;e>=left;e--)
	{
		for(int p=mid;p<=right;p++)
		{
			if((arr[e].first-arr[p].first)*(arr[e].first-arr[p].first)>cc) break;
			rmin=min(rmin,cal(e,p));
		}
	}
	return min(rmin,cc);
}
int main(void)
{
	cin >> n;
	for(int e=0;e<n;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[e]=make_pair(a,b);
		minn=min(minn,a);
		mann=max(mann,a);
	}
	sort(arr,arr+n);
	for(int e=0;e<n-1;e++)
	{
		if(arr[e].first==arr[e+1].first&&arr[e].second==arr[e+1].second)
		{
			cout << "0";
			return 0;
		}
	}
	
	cout <<	recur(0,n-1);
}

