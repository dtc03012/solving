#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
struct inf{
	long long int x,y,p,q;
};
long long int abss(long long int a)
{
	return a>0?a:-a;
}
inf arr[111111];
bool tmr(inf a,inf b)
{
	if(a.q*b.p!=a.p*b.q) return a.q*b.p<a.p*b.q;
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
long long int ccw(inf a,inf b,inf c)
{
	return (b.y-a.y)*(a.x-c.x)-(a.x-b.x)*(c.y-a.y);
}
long long int getarr(inf a,inf b,inf c)
{
	long long int fx=c.x-a.x,fy=c.y-a.y,sx=c.x-b.x,sy=c.y-b.y;
	return abs(fx*sy-sx*fy)/2;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int e=0;e<n;e++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			arr[e].x=2*a;
			arr[e].y=2*b;
			arr[e].p=1;
			arr[e].q=0;
		}
		sort(arr,arr+n,tmr);
		for(int e=1;e<n;e++)
		{
			arr[e].p=arr[e].x-arr[0].x;
			arr[e].q=arr[e].y-arr[0].y;
		}
		sort(arr+1,arr+n,tmr);
		stack<int> s;
		s.push(0);
		s.push(1);
		int next=2;
		while(next<n)
		{
			while(s.size()>=2)
			{
				int f=s.top();
				s.pop();
				int r=s.top();
				if(ccw(arr[r],arr[f],arr[next])>0) 
				{
					s.push(f);
					break;
				}
			}
			s.push(next++);
		}
		cout << s.size() << endl;
	}
}
