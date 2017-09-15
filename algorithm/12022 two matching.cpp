#include <stdio.h>
#include <vector>
#include <string.h>
#define m 1001
using namespace std;
int arr[2222][2222];
int a[2222],b[2222],vis[2222],n;
bool dfs(int now,int left,int value)
{
	vis[now]=1;
	for(int e=m;e<m+n;e++)
	{
		int pp=0;
		if(left!=-1)
		{
			if(arr[left][e]>arr[left][value]&&arr[e][left]>arr[e][now]) pp++;
			if(arr[now][value]>arr[now][e]&&arr[value][now]>arr[value][left]) pp++;
		}
		if(pp==0)
		{
			if(b[e]==-1||vis[b[e]]==0&&dfs(b[e],now,e))
			{
				b[e]=now;
				a[now]=e;
				return true;
			}
		}
	}
	return false;
}
int main(void)
{
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	scanf("%d",&n);
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<n;p++)
		{
			int k;
			scanf("%d",&k);
			arr[e][k+m-1]=p+1;
		}
	}
	for(int e=0;e<n;e++)
	{
		for(int p=0;p<n;p++)
		{
			int k;
			scanf("%d",&k);
			arr[e+m][k-1]=p+1;
		}
	}
	for(int e=0;e<n;e++)
	{
		memset(vis,0,sizeof(vis));
		if(e==0) dfs(e,-1,-1);
		else dfs(e,e-1,a[e-1]);
	}
	for(int e=0;e<n;e++) printf("%d\n",a[e]-m+1);
}
