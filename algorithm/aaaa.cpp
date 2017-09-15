#include <stdio.h>
#include <string.h>
#include <queue>
#define mod 1000000007
using namespace std;

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		priority_queue<long long int> q;
		for(int e=0;e<n;e++){
			long long int k;
			scanf("%lld",&k);
			q.push(-k);
		}
		long long int tot=1;
		while(!q.empty()){
			if(q.size()==1) {
				break;
			}
			long long int now=-q.top();q.pop();
			long long int now2=-q.top();q.pop();
			tot=(tot*((now*now2)%mod))%mod;
			q.push(-(now*now2));
		}
		printf("%lld\n",tot);
	}
}
