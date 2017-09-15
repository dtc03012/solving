#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		string a,b;
		double k;
		cin >> a >> b >> k;
		if(a=="H")
		{
			double f=log10(k);
			printf("%0.2lf\n",-f);
		}
		else
		{
			double f=log10(k);
			printf("%0.2lf\n",14+f);
		}
	}
}
