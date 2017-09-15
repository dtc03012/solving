#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long int aa=1,kk=1;

int main(void)
{
	string tmp;
	cin >> tmp;
	while(1)
	{
		long long int rrr=aa,eee=0;
		vector<int> rr;
		while(rrr!=0)
		{
			rr.push_back(rrr%10);
			rrr/=10;
		}
		cout << "Asfd " <<rrr << endl;
		int tsa;
		cin >>tsa;
		for(int e=rr.size(),p=0;e>rr.size()-5;e--,p++) 
		{
			if(rr[e]!=tmp[p]) eee++;
		}
		if(eee==0)
		{
			cout << kk;
			return 0;
		}
		aa*=kk;
		kk++;
		long long int tttt=0;
		rrr=aa;
		while(rrr!=0)
		{
			rrr/=10;
			tttt++;
		}
		if(tttt>15)
		{
			for(int e=tttt;e>15;e--) aa/=10;
		}
	}
}
