#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> arr[111111];
int seg[444444],p=1;
bool tmr(pair<int,int> f,pair<int,int> s)
{
	if(f.first<s.first) return true;
	if(f.first>s.first) return false;
	if(f.second<s.second) return true;
	return false;
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		memset(seg,0,sizeof(seg));
		memset(arr,0,sizeof(arr));
		p=1;
		scanf("%d",&n);
		for(int e=0;e<n;e++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			arr[a]=make_pair(b,c); 
		}
		while(n>p) p*=2;
		for(int e=1;e<p*2;e++) seg[e]=987654321;
		int tot=n;
		for(int e=1;e<=n;e++)
		{
 			int left=p,right=p+arr[e].first-1,tt=0;
			while(left<=right){
				if(left%2){
					if(seg[left]<arr[e].second) tt++;
					left++;
				}
				if(!(right%2)){
					if(seg[right]<arr[e].second) tt++;
					right--;
				}
				left/=2;
				right/=2;
			}
			if(tt) tot--;
			seg[p+arr[e].first]=arr[e].second;
			for(int k=(p+arr[e].first)/2;k>=1;k/=2) seg[k]=min(seg[k*2],seg[k*2+1]);
		}
		printf("%d\n",tot);
	}
}
