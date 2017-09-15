#include <iostream>
#include <string>

using namespace std;
int rr=0,pp=0;
int main(void)
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	for(int e=0;e<b.size();e++)
	{
		if(b[e]==' ')
		{
			rr=max(rr,pp);
			pp=0;
		}
		if(b[e]>='A'&&b[e]<='Z') pp++;
	}
	rr=max(rr,pp);
	cout << rr;
}
