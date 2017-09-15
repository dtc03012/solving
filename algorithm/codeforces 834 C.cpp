#include <iostream>
#include <string>
using namespace std;
int arr[5555][5555],pp[5555];
string a;
int main(void)
{
	cin >> a;
	for(int e=0;e<a.size();e++)
	{
		for(int p=e;p>=0;p--)
		{
			if(a[e]==a[p])
			{
				if(e-1<p+1) 
				{
					arr[p][e]=1;
					if(p+1==e)
					{
						arr[p][e]=2;
					}
				}
				else 
				{
					if(arr[p+1][e-1]) 
					{
						arr[p][e]=1;
						int kk=(e-p+1)/2;
						if(arr[p][p+kk-1]==arr[e-kk+1][e])
						{
							arr[p][e]=arr[p][p+kk-1]+1;
						}
					}
				}
			}
		}
	}
	int n=0;
	for(int e=0;e<a.size();e++)
	{
		for(int p=0;p<a.size();p++) 
		{
			for(int q=1;q<=arr[e][p];q++) pp[q]+=1;
		}
	}
	for(int e=1;e<=a.size();e++) cout << pp[e] << " ";
}
