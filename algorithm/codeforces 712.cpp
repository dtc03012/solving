#include <iostream>
#include <queue>
using namespace std;
int c[211111];
int main(void)
{
	int n;
	cin >> n;
	priority_queue<int> p;
	priority_queue<pair<int,int> > q;
	for(int e=0;e<n;e++)
	{
		int k;
		cin >> k;
		p.push(k);
	}
	for(int e=0;e<n;e++)
	{
		int k;
		cin >> k;
		q.push(make_pair(-k,e));
	}
	for(int e=0;e<n;e++)
	{
		c[q.top().second]=p.top();
		q.pop();
		p.pop();
	}
	for(int e=0;e<n;e++) cout << c[e] << " ";
}
