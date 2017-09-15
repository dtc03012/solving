#include <iostream>

using namespace std;
int n,a,b,maxs=0;
pair<int,int> inf[111];
bool cc(pair<int,int> m)
{
	if(m.first>a||m.second>b) return false;
	return true;
}
bool check2(pair<int,int> f,pair<int,int> s)
{
	if(f.first+s.first<=a&&max(f.second,s.second)<=b) return true;
	if(max(f.first,s.first)<=a&&f.second+s.second<=b) return true;
	return false;
}
bool check(pair<int,int> m,pair<int,int> n)
{
	pair<int,int> f,s;
	f=make_pair(m.second,m.first);
	s=make_pair(n.second,n.first);
	if(cc(m)&&cc(n))
	{
		if(check2(m,n)) return true;
	}
	if(cc(m)&&cc(s))
	{
		if(check2(m,s)) return true;
	}
	if(cc(f)&&cc(n))
	{
		if(check2(f,n)) return true;
	}
	if(cc(f)&&cc(s))
	{
		if(check2(f,s)) return true;
	}
	return false;
}
int main(void)
{
	cin >> n >> a >> b;
	for(int e=0;e<n;e++) cin >> inf[e].first >> inf[e].second;
	for(int e=0;e<n;e++)
	{
		for(int p=e+1;p<n;p++)
		{
			if(check(inf[e],inf[p]))
			{
				maxs=max(maxs,inf[e].first*inf[e].second+inf[p].first*inf[p].second);
			}
		}
	}
	cout << maxs;
}
