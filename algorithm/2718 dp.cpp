#include <iostream>
#include <string.h>
using namespace std;
int arr[111];
int main(void)
{
	int n;
	cin >> n;
	arr[0]=1;
	arr[1]=1;
	arr[2]=5;
	for(int e=3;e<111;e++)
	{
		int kk=arr[e-1]+arr[e-2],pp=0;
		for(int p=e-2;p>=0;p--)
		{
			if(pp%2) kk+=2*arr[p];
			else kk+=3*arr[p];
			pp++;
		}
		arr[e]=kk;
	}
	while(n--)
	{
		int t;
		cin >> t;
		cout << arr[t] << "\n";
	}
}
