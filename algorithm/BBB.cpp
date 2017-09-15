#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
vector<int> arr[5555];
int kk[5555];
int main(void){
	memset(kk,-1,sizeof(kk));
	priority_queue<pair<int,int> > q;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		int a,b;
		scanf("%d",&a);
		q.push(make_pair(a,e));
	}
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	while(!q.empty()){
		int now=q.top().first,rr=q.top().second,er=-1;q.pop();
		cout << rr << " " << now << endl;
		for(int e=0;e<arr[rr].size();e++){
			int next=arr[rr][e];
			if(kk[next]>er){
				er=kk[next];
			}
		}
		if(er==-1) kk[rr]=1;
		else{
			kk[rr]=er+1;
		}
	}
	for(int e=1;e<=n;e++) printf("%d\n",kk[e]);
}
