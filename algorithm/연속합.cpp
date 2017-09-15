#include <iostream>
#include <vector>
using namespace std;
vector<int> kk;
int main(void)
{
	int n,ma=0,tt=0,pp=-1111,wh;
	cin >> n;
	for(int e=0;e<n;e++)
	{
		int k;
		cin >> k;
		tt+=k;
		pp=max(pp,tt);
		if(tt<0) tt=0;
	}
	cout << pp; 
}
