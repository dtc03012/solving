#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	string tmp;
	cin >> tmp;
	stack<int> s;
	for(int e=0;e<tmp.size();e++)
	{
		if(tmp[e]=='H')
		{
			s.push(1);
		}
		else if(tmp[e]=='C')
		{
			s.push(12);
		}
		else if(tmp[e]=='O')
		{
			s.push(16);
		}
		else if(tmp[e]=='(')
		{
			s.push(-1);
		}
		else if(tmp[e]>='2'&&tmp[e]<='9')
		{
			int now=s.top();s.pop();
			s.push(now*(tmp[e]-'0'));
		}
		else if(tmp[e]==')')
		{
			int tot=0;
			while(!s.empty())
			{
				int now=s.top();s.pop();
				if(now==-1) 
				{
					s.push(tot);
					break;
				}
				tot+=now;
			}
		}
	}
	int tot=0;
	while(!s.empty())
	{
		tot+=s.top();s.pop();
	}
	cout << tot;
}
