#include <iostream>
using namespace std;
long long int dp[101][10][1111];
int main(void)
{
	for(int e=1;e<10;e++) dp[0][e][1<<e]=1;
	int n;
	cin >> n;
	for(int e=1;e<n;e++)
	{
		for(int p=1;p<1024;p++) dp[e][0][p|(1<<0)]+=dp[e-1][1][p]%1000000000;
		for(int q=1;q<9;q++) for(int p=1;p<1024;p++) 
		{
			dp[e][q][p|(1<<q)]+=(dp[e-1][q-1][p]+dp[e-1][q+1][p])%1000000000;
		}
		for(int p=1;p<1024;p++) dp[e][9][p|(1<<9)]+=dp[e-1][8][p]%1000000000;
	}
	long long int tot=0;
	for(int e=0;e<10;e++) tot+=dp[n-1][e][1023];
	cout << tot%1000000000 << endl;
	return 0;
}
