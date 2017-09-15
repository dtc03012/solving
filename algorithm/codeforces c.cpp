#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[111111];
long long int depth[111111],kk[111111];
double tt=0,qq=0,rr2=0;
double recur(int n)
{
	double pp=0,qqq=0;
	for(int e=0;e<arr[n].size();e++)
	{
		int next=arr[n][e];
		if(depth[next]==-1)
		{
			pp++;
			depth[next]=depth[n]+1;
			double now=recur(next);
			if(n==1) qqq+=now/arr[1].size();
			else qqq+=now/(arr[n].size()-1);
		}
	}
	if(pp==0) 
	{
		return depth[n];
	}
	return qqq;
}
int main(void)
{
	memset(depth,-1,sizeof(depth));
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	depth[1]=0;
	kk[1]=1;
	printf("%0.10lf",recur(1));
}
