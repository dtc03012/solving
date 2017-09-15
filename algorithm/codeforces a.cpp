#include <iostream>

using namespace std;
int n,k,tt;
int main(void)
{
	cin >> n >> k;
	for(int e=1;e<=n;e++)
	{
		int f;
		cin >> f;
		tt+=f;
		if(tt>=8) 
		{
			k-=8;
			tt-=8;
			if(k<=0)
			{
				cout << e ;
				return 0;
			}
		}
		else
		{
			k-=tt;
			tt=0;
			if(k<=0)
			{
				cout << e;
				return 0;
			}
		}
	}
	cout << "-1";
}
