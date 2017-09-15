#include <iostream>
#include <algorithm>
using namespace std;
pair<long long int,long long int> arr[111111];
bool tmr(pair<long long int,long long int> a,pair<long long int,long long int> b)
{
	return a.second < b.second;
}
int main(void)
{
	long long int n,tot=0,kk=0,rr=0;
	cin >> n;
	for(int e=0;e<n;e++)
	{
		long long int a,b;
		cin >> a >> b;
		arr[e].first=a;
		arr[e].second=b;
		tot+=b;
	}
	sort(arr,arr+n);
	tot/=2;
	cout << tot << endl;
	while(kk<=tot)
	{
		kk+=arr[rr].second;
		rr++;
	}
	cout << arr[rr-1].first;
}
