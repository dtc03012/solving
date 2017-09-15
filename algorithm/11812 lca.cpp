#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	long long int n,k,qq;
	cin >> n >> k >> qq;
	while(qq--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(k==1)
		{
			printf("%lld\n",max(a,b)-min(a,b));
			continue;
		}
		vector<long long int> p,q;
		p.push_back(a);
		q.push_back(b);
		long long int f=a,s=b;
		while(f!=1)
		{
			long long int now=f%k;
			if(now<=1) f/=k;
			else f=(f/k)+1;
			p.push_back(f);
		}
		while(s!=1)
		{
			long long int now=s%k;
			if(now<=1) s/=k;
			else s=(s/k)+1;
			q.push_back(s);
		}
		sort(q.begin(),q.end());
		long long int tot=0;
		for(int e=0;e<p.size();e++)
		{       
			if(binary_search(q.begin(),q.end(),p[e]))
			{
				tot+=e;
				for(int r=0;r<q.size();r++)
				{
					if(q[r]==p[e])
					{
						tot+=q.size()-r-1;
						break;
					}
				}
				break;
			}
		}
		printf("%lld\n",tot);
	}
}
