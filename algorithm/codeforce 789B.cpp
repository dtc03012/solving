#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
long long int arr[111111];
int abs(int a)
{
	return a>0?a:-a;
}
map<int,int> aa;
int main(void)
{
	long long int b,q,l,m;
	cin >> b >> q >> l >> m;
	for(int e=0;e<m;e++) cin >> arr[e];
	sort(arr,arr+m);
	long long int kk=b,tot=0,rr=0;
	for(int e=0;e<11111;e++)
	{
		if(abs(kk)>l) break;
		if(binary_search(arr,arr+m,kk)==0) 
		{
			tot++;
			if(aa[kk]) 
			{
				cout << "inf";
				return 0;
			}
		}
		aa[kk]++;
		kk*=q;
	}
	cout << tot;
}
