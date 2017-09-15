#include <iostream>
#include <stack>
#include <string>
using namespace std;
char dp[111][111];
string tmp;
stack<char> s;
int main(void)
{
	dp['A']['A']='A';
	dp['A']['G']='C';
	dp['A']['C']='A';
	dp['A']['T']='G';
	dp['G']['A']='C';
	dp['G']['G']='G';
	dp['G']['C']='T';
	dp['G']['T']='A';
	dp['C']['A']='A';
	dp['C']['G']='T';
	dp['C']['C']='C';
	dp['C']['T']='G';
	dp['T']['A']='G';
	dp['T']['G']='A';
	dp['T']['C']='G';
	dp['T']['T']='T';
	int n;
	cin >> n;
	cin >> tmp;
	for(int e=0;e<tmp.size();e++) s.push(tmp[e]);
	while(s.size()!=1)
	{
		char f=s.top();s.pop();
		char k=s.top();s.pop();
		s.push(dp[f][k]);
	}
	cout << s.top();
}
