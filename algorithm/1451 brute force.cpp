#include <iostream>
#include <string>

using namespace std;
string tmp[111];
int n,m;
int main(void)
{
	cin >> n >> m ;
	for(int e=0;e<n;e++) cin >> tmp[e];
	long long int mm=0;
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<m;p++)
		{
			long long int kk=0;
			for(int r=0;r<=e;r++) for(int q=0;q<=p;q++) kk+=tmp[r][q]-'0';
			if(e!=n-1&&p!=m-1)
			{
				long long int rr=0,qq=0;
				for(int r=e+1;r<n;r++) for(int q=0;q<=p;q++) rr+=tmp[r][q]-'0';
				for(int r=0;r<n;r++) for(int q=p+1;q<m;q++) qq+=tmp[r][q]-'0';
				mm=max(mm,rr*qq*kk);
				rr=0;qq=0;
				for(int r=e+1;r<n;r++) for(int q=0;q<m;q++) rr+=tmp[r][q]-'0';
				for(int r=0;r<=e;r++) for(int q=p+1;q<m;q++) qq+=tmp[r][q]-'0';
				mm=max(mm,rr*qq*kk);
			}
			if(e==n-1)
			{
				long long int rr=0,tt=0;
				for(int r=0;r<n;r++) for(int q=p+1;q<m;q++) rr+=tmp[r][q]-'0';
				for(int r=0;r<n-1;r++)
				{
					for(int q=p+1;q<m;q++) tt+=tmp[r][q]-'0';
					mm=max(mm,kk*tt*(rr-tt));
				}
				tt=0;
				for(int r=p+1;r<m-1;r++)
				{
					for(int q=0;q<n;q++) tt+=tmp[q][r]-'0';
					mm=max(mm,kk*tt*(rr-tt));
				}
			}
			if(p==m-1)
			{
				long long int rr=0,tt=0;
				for(int r=e+1;r<n;r++) for(int q=0;q<m;q++) rr+=tmp[r][q]-'0';
				for(int r=0;r<m-1;r++)
				{
					for(int q=e+1;q<n;q++) tt+=tmp[q][r]-'0';
					mm=max(mm,kk*tt*(rr-tt));
				}
				tt=0;
				for(int r=e+1;r<n-1;r++)
				{
					for(int q=0;q<m;q++) tt+=tmp[r][q]-'0';
					mm=max(mm,kk*tt*(rr-tt));
				}
			}
		}
	}
	cout << mm << endl;
}
