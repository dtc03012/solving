#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[11111];
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,mm=0;
		scanf("%d",&n);
		for(int e=0;e<n;e++) scanf("%d",&arr[e]);
		sort(arr,arr+n);
		int l=arr[0],r=arr[0];
		for(int e=1;e<n-1;e++) 
		{
			if(e%2) 
			{
				mm=max(mm,arr[e]-l);
				l=arr[e];
			}
			else
			{
				mm=max(mm,arr[e]-r);
				r=arr[e];
			}
		}
		mm=max(mm,max(arr[n-1]-r,arr[n-1]-l));
		printf("%d\n",mm);
	}
}
