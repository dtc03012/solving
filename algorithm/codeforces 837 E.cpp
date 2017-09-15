#include <iostream>
#include <vector>
using namespace std;
int arr[1111111];
vector<int> k,kk;
long long int gcd(long long int a,long long int b)
{
	long long int tmp;
	while(b!=0)
	{
		tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
int main(void)
{
	for(int e=2;e<1111111;e++) if(arr[e]==0) for(int p=e*2;p<1111111;p+=e) arr[p]=1;
	for(int e=2;e<1111111;e++) if(arr[e]==0) kk.push_back(e);
	long long int a,b,tot=0;
	cin >> a >> b;
	while(b!=0)
	{
		long long int now=gcd(a,b);
		if(a==1)
		{
			tot+=b;
			break;
		}
		if(now==1)
		{
			long long int kks=987654321,wh=-1;
			for(int p=0;p<kk.size();p++) 
			{
				if(a%kk[p]==0)
				{
					if(kks>b%kk[p])
					{
						kks=b%kk[p];
						wh=p;
					}
				}
			}
			if(wh==-1)
			{
				kks=b%a;
			}
			tot+=kks;
			b-=kks;
		}
		else
		{
			a/=now;
			b/=now;
		}
	}
	cout << tot;
}
