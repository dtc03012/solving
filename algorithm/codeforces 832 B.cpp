#include <iostream>
#include <string>

using namespace std;
int vis[26];
int main(void)
{
	string a,b;
	cin >> a >> b;
	for(int e=0;e<a.size();e++) vis[a[e]-'a']=1;
	int n;
	cin >> n;
	while(n--)
	{
		int pp=0,wh=-1;
		string c;
		cin >> c;
		for(int p=0;p<max(b.size(),c.size());p++)
		{
			if(p<b.size()&&b[p]=='*')
			{
				wh=p;
				break;
			}
			if(p==b.size()||p==c.size())
			{
				pp++;
				break;
			}
			if(b[p]=='?')
			{
				if(vis[c[p]-'a']==0) pp++;
				continue;	
			}
			if(b[p]!=c[p]) pp++;
		}
		if(wh!=-1)
		{
			int f=wh+1,s=wh;
			if(c.size()+1<b.size()) pp++;
			s+=c.size()-b.size()+1;
			for(int p=wh;p<s;p++)
			{
				if(vis[c[p]-'a']==1) pp++;
			}
			if(pp==0)
			{
				for(int p=0;p<b.size()-f;p++)
				{
					if(b[f+p]=='?')
					{
						if(vis[c[s+p]-'a']==0) pp++;
						continue;
					}
					if(b[f+p]!=c[s+p]) pp++;
				}
			}
		}
		if(pp)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
}
