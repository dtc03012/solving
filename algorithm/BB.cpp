#include <stdio.h>
#include <queue>

using namespace std;
const int inf = 987654321;
int dp[7205];
void solve() {
	int N, T; scanf("%d %d", &N, &T);
	int d[16];
	for (int i=0; i<N; i++) scanf("%d", d+i);
	for (int i=0; i<=7200; i++) dp[i] =inf;
	dp[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for (int i=0; i<N; i++) {
			int nxt = now + d[i];
			//if (nxt > 7200) continue;
			if (nxt >= 3600) nxt = 3600;
			if (nxt < 0 ) nxt = 0;
			if (dp[nxt] > dp[now] + 1) {
				dp[nxt] = dp[now] + 1;
				q.push(nxt);
			}
		}
	}
	
	if (dp[T] < inf) {
		printf("%d %d\n", dp[T], T-T);
		return;
	}
	else {
		
		for (int i=T; i<=3600; i++) {
			if (dp[i] < inf) {
				printf("%d %d\n", dp[i], T-i);
				return;
			}
		}
	}	
	printf("%d\n", 0/0);
	return;
}
			
int main(void) {
	int T; scanf("%d", &T);
	while(T--) {
		solve();	
	}
}
