#include <iostream>

using namespace std;
int arr[33],arr2[33],n,kk=0;
int main(void)
{
	arr[1]=1;
	arr[2]=3;
	arr2[1]=1;
	arr2[2]=3;
	for(int e=3;e<33;e++) 
	{
		arr[e]+=arr[e-2];
		if(e>=4) arr[e]+=arr[e-4];
		arr2[e]=arr2[e-1]+2*arr2[e-2];
	}
	for(int e=3;e<33;e++) arr2[e]=arr[e]+(arr2[e]-arr[e])/2;
	cin >> n;
	cout << arr2[n];
}
