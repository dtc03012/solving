#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;
pair<int,int> arr[5555];
int check[5555],f,s;
double ma=0,rr=987654321;
vector<pair<double,int> > inf;
double a[5555],b[5555];
double cal(int a,int b)
{
	return (double)(sqrt((arr[a].first-arr[b].first)*(arr[a].first-arr[b].first)+(arr[a].second-arr[b].second)*(arr[a].second-arr[b].second)));
}
bool tmr(pair<double,int> a,pair<double,int> b)
{
	return a.first < b.first;
}
int main(void)
{
	int n;
	cin >> n;
	for(int e=0;e<n;e++) scanf("%d%d",&arr[e].first,&arr[e].second);
	for(int e=0;e<n;e++)
	{
		for(int p=e+1;p<n;p++)
		{
			double rrr=cal(e,p);
			if(rrr>=ma)
			{
				ma=rrr;
				f=e;
				s=p;
			}
		}
	}
	for(int e=0;e<n;e++) inf.push_back(make_pair(cal(e,f),e));
	sort(inf.begin(),inf.end(),tmr);
	for(int e=0;e<n;e++)
	{
		if(e) a[e]=a[e-1];
		for(int p=0;p<n;p++)
		{
			if(check[p])
			{
				a[e]=max(a[e],cal(p,inf[e].second));
			}
		}
		check[inf[e].second]=1;
	}
	memset(check,0,sizeof(check));
	for(int e=n-2;e>=0;e--)
	{
		b[e]=b[e+1];
		for(int p=0;p<n;p++)
		{
			if(check[p])
			{
				b[e]=max(b[e],cal(p,inf[e+1].second));
			}
		}
		check[inf[e+1].second]=1;
	}
	for(int e=0;e<n;e++) rr=min(rr,a[e]+b[e]);
	printf("%0.5lf",rr);
}
