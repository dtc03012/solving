#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	long long int a,b=0;
	cin >> a;
	for(int e=2;e<=(a/2);e++) b=(b+((a/e)-1)*e)%1000000;
	cout << b << endl;
}
