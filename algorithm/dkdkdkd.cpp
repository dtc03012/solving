#include <iostream>
#include <vector>
#include <math.h>
#define mod 1000000007
using namespace std;
vector<pair<int,int> > a;
long long int arr[333],n,tot=0,pp[333];
bool squr(long long int rr)
{
	long long int now=sqrt(rr);
	if(now*now==rr) return true;
	return false;
}
int main(void)
{
	cin >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
	pp[0]=1;
	pp[1]=1;
	for(int e=2;e<333;e++) pp[e]=(pp[e-1]*e)%mod;
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<n;p++)
		{
			if(e==p) continue;
			if(squr(arr[e]*arr[p]))
			{
				a.push_back(make_pair(e,p));
			}
		}
	}
	tot=pp[n];
	for(int e=0;e<a.size();e++)
	{
		if(n>=2)tot-=pp[n-2];
		int tt=0,kk=0;
		for(int p=0;p<n;p++)
		{
			if(p!=a[e].first&&-p!=a[e].second)
			{
				if(!squr(arr[p]*arr[a[e].first]))
				{
					tt++;
				}
			}
		}
		if(n>=3) tot-=(tt*pp[n-3])%mod;
		for(int p=0;p<n;p++)
		{
			if(p!=a[e].first&&p!=a[e].second)
			{
				if(!squr(arr[p]*arr[a[e].first]))
				{
					for(int q=0;q<n;q++)
					{
						if(q!=a[e].first&&q!=a[e].second&&q!=p)
						{
							if(!squr(arr[q]*arr[p]))
							{
								kk++;
							}
						}
					}
				}
			}
		}
		cout << a[e].first << " " <<a[e].second << " " << tt << " " << kk << endl;
		if(n>=4) tot-=(kk*pp[n-4])%mod;
	}
	cout << tot;
}
