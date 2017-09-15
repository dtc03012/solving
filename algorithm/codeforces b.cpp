#include <iostream>

using namespace std;
int arr[111];
int main(void)
{
	int n,k,a=0,b=1;
	cin >> n >> k;
	for(int e=0;e<k;e++)
	{
		int t;
		cin >> t;
		a+=t;
		if(a%8==1) a+=1;
		else if(a%8==2) a+=1;
		else if(a%8==3) a+=1;
		else if(a%8==5) a+=1;
		else if(a%8==7) a+=1;
	}
	if(((a-1)/8)+1>n) cout << "NO";
	else cout << "YES";
}
