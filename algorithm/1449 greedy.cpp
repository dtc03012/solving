#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1111];
int main(void)
{
	int n,m,tt=0,qq;
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> arr[e];
	sort(arr,arr+n);
	tt++;
	qq=arr[0]+m;
	for(int e=1;e<n;e++)
	{
		if(arr[e]>=qq)
		{
			tt++;
			qq=arr[e]+m;
		}
	}
	cout << tt;
}
