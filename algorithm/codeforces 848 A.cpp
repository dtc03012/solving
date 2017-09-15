#include <iostream>
#include <string>

using namespace std;
string tmp;
int main(void)
{
	long long int n,q=0;
	cin >> n;
	if(n==0) cout << "a";
	while(n!=0)
	{
		long long int p=1;
		while((p*(p-1))/2<=n) p++;
		p--;
		for(int e=0;e<p;e++) tmp+=char('a'+q);
		q++;
		n-=(p*(p-1))/2;
	}
	cout << tmp;
}
