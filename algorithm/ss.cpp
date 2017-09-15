#include <bits/stdc++.h>
#define fr(x) scanf("%d", &x)
using namespace std;

vector<pair<int, int> > g[300010];
int vis[300010];
set<int> s;

signed main(){
	int n, k, d;
	fr(n);
	fr(k);
	fr(d);
	queue<int> q;
	for(int i=1;i<=k;++i){
		int p;
		fr(p);
		q.push(p);
		vis[p]=1;
	}
	for(int i=1;i<n;++i){
		int u,v;
		fr(u);
		fr(v);
		g[u].push_back({v, i});
		swap(u, v);
		g[u].push_back({v, i});
		s.insert(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto&v:g[u]){
			if(!vis[v.first]){
				q.push(v.first);
				s.erase(v.second);
				vis[v.first]=1;
			}
		}
	}
	printf("%d\n", s.size());
	for(auto&z:s){
		printf("%d ",z);
	}
	return 0;
}
