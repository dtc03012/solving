#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
struct xy{
	long long int x,y,p,q;
};
xy arr[111111];
bool tmr(xy a,xy b)
{
	if(a.p*b.q!=a.q*b.p) return a.q*b.p < b.q*a.p;
	if(a.y!=b.y) return a.y < b.y;
	return a.x < b.x;
}
long long ccw(xy a,xy b,xy c)
{
	return (c.y-a.y)*(b.x-a.x)-(c.x-a.x)*(b.y-a.y);
}
int main(void)
{
	int n;
	cin >> n;
	for(int e=0;e<n;e++)
	{
		long long int a,b;
		cin >> a >> b;
		arr[e].x=a;
		arr[e].y=b;
		arr[e].p=1;
		arr[e].q=0;
	}
	sort(arr,arr+n,tmr);
	for(int e=1;e<n;e++)
	{
		arr[e].p=(arr[e].x-arr[0].x);
		arr[e].q=(arr[e].y-arr[0].y);
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
			int first=s.top();
			s.pop();
			int second=s.top();
			if(ccw(arr[second],arr[first],arr[next])>0)
			{
				s.push(first);
				break;
			}
		}
		s.push(next++);
	}
	cout << s.size();
}
