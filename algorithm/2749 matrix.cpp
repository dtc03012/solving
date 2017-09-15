#include <iostream>

using namespace std;

struct inf{
	long long int a[2][2];
};
inf b;
inf mult(inf f,inf s)
{
	inf kk;
	for(int e=0;e<2;e++)
	{
		for(int p=0;p<2;p++)
		{
			long long int tt=0;
			for(int q=0;q<2;q++)
			{
				tt=(tt+f.a[e][q]*s.a[p][q])%1000000;
			}
			kk.a[e][p]=tt;
		}
	}
	return kk;
}
inf recur(long long int n)
{
	if(n==1) return b;
	inf aa=recur(n/2);
	if(n%2) return mult(aa,mult(aa,b));
	else return mult(aa,aa);
}
int main(void)
{
	long long int n;
	b.a[0][0]=1;
	b.a[0][1]=1;
	b.a[1][0]=1;
	cin >> n;
	if(n==0) c
	if(n==1) cout << "1";
	else if(n==2) cout << "110010";
	else{
		inf ttt=recur(n-1);
		cout << ttt.a[0][0];
	}
}
