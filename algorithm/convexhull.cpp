#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct inf{
	int x,y,p,q;
};
inf arr[111111];
bool tmr(inf a,inf b)
{
	if(a.q*b.p!=a.p*b.q) return a.q*b.p<a.p*b.q;
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
int ccw(inf a,inf b,inf c)
{
	return (b.y-a.y)*(a.x-c.x)-(a.x-b.x)*(c.y-a.y);
}
int main(void)
{
	int n;
	cin >> n;
	for(int e=0;e<n;e++)
	{
		int a,b;
		cin >> a >> b;
		arr[e].x=a;
		arr[e].y=b;
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
	cout << s.size();
}
