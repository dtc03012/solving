#include <iostream>
using namespace std;

int main(void)
{
	int a,b,c[4],k=0;
	cin >> a >> b;
	for(int e=0;e<3;e++) c[e]=b;
	while(1)
	{
		int pp=0;
		for(int e=0;e<3;e++) if(c[e]>=a) pp++;
		if(pp==3) break;
		int dd=0;
		for(int e=0;e<3;e++)
		{
			if(e==(k%3)) continue;
			dd+=c[e];
		}
		c[k%3]=dd-1;
		k++;
	}
	cout << k;
}
