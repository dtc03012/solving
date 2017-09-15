#include <iostream>
#include <algorithm>
using namespace std;
int arr[111111],p=0;
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> arr[e];
	sort(arr,arr+n);
	int pp=0;
	for(int e=0;e<n;e++) pp+=(arr[e]/m)+(arr[e]%m?1:0);
	cout << pp/2+(pp%2?1:0);
}
