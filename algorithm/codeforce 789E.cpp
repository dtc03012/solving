#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
int vis[1111];
vector<int> kk,minuss,pluss;
int pp[1111111],mm[1111111];
int main(void)
{
	int n,k;
	scanf("%d%d",&k,&n);
	for(int e=0;e<n;e++)
	{
		int p;
		scanf("%d",&p);
		if(vis[p]==0) kk.push_back(p);
		vis[p]=1;
	}
	for(int e=0;e<=1000000;e++)
	{
		pp[e]=987654321;
		mm[e]=987654321;
	}
	for(int e=0;e<kk.size();e++) kk[e]-=k;
	for(int e=0;e<kk.size();e++)
	{
		if(kk[e]==0)
		{
			cout << "1";
			return 0;
		}
		if(kk[e]>0)
		{
			pp[kk[e]]=1;
			pluss.push_back(kk[e]);
		}
		else 
		{
			mm[-kk[e]]=1;
			minuss.push_back(-kk[e]);
		}
	}
	for(int e=0;e<pluss.size();e++)
	{
		for(int p=pluss[e]+1;p<=1000000;p++)
		{
			pp[p]=min(pp[p],pp[p-pluss[e]]+1);
		}
	}
	for(int e=0;e<minuss.size();e++)
	{
		for(int p=minuss[e]+1;p<=1000000;p++)
		{
			mm[p]=min(mm[p],mm[p-minuss[e]]+1);
		}
	}
	int kk=987654321;
	for(int e=1;e<=1000000;e++) 
	{
		kk=min(kk,mm[e]+pp[e]);
	}
	if(kk==987654321) cout <<"-1";
	else cout << kk;
}
