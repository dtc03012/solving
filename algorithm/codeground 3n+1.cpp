#include <iostream>
#include <map>
#include <queue>
using namespace std;
unsigned long long int maxs=0,mins=2e18;
void dfs(unsigned long long int a,int p)
{
	if(p==0) 
	{
		maxs=max(maxs,a);
		mins=min(mins,a);
		return;
	}
	dfs(a*2,p-1);
	if((a-1)%3==0&&(a-1)/3!=1&&(a-1)/3!=0&&((a-1)/3)%2==1)
	{
		dfs((a-1)/3,p-1);
	}
}
int main(void)
{
	int t;
	cin >> t;
	for(int r=1;r<=t;r++)
	{
		long long int a;
		maxs=0;
		mins=2e18;
		cin >> a;
		dfs(1,a);
		cout << "Case #"<<r<<"\n";
		cout << mins << " " << maxs << "\n";
	}
}
