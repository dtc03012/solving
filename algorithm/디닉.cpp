#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX_V = MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;
 
int N, c[MAX_V][MAX_V], f[MAX_V][MAX_V];
int level[MAX_V]; // ���� �׷������� ������ ����(S�� 0)
int work[MAX_V]; // dfs ��, �� ������ �� ��° �������� Ž���ߴ��� ����ϴ� �뵵
vector<int> adj[MAX_V];
 
// ��� ���� bfs �Լ�
bool bfs(){
    // ������ �ʱ�ȭ
    fill(level, level+MAX_V, -1);
    level[S] = 0;
    
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next: adj[curr]){
            // �������� �������� �ʾҰ�, ������ residual�� ���� ���� �̵�
            if(level[next] == -1 && c[curr][next]-f[curr][next] > 0){
                level[next] = level[curr] + 1; // next�� ������ curr�� ���� + 1
                Q.push(next);
            }
        }
    }
    // ��ũ�� ���� �����ϸ� true, �ƴϸ� false�� ����
    return level[E] != -1;
}
 
// ��� ���� dfs �Լ�: curr���� dest���� �ִ� flow��ŭ�� ������ ���� ��
int dfs(int curr, int dest, int flow){
    // base case: dest�� ������
    if(curr == dest) return flow;
 
    // ���� �������� ������ �������� Ž��
    // �̶�, �̹� �ܰ迡�� �̹� ������ٰ� �Ǵ��� ������ �ٽ� �� �ʿ䰡 �����Ƿ�
    // work �迭�� ���� �ε����� ������ ��
    for(int &i=work[curr]; i<adj[curr].size(); i++){
        int next = adj[curr][i];
        // next�� ������ curr�� ���� + 1�̰�, ������ residual�� �����־�߸� �̵�
        if(level[next] == level[curr]+1 && c[curr][next]-f[curr][next] > 0){
            // df: flow�� ���� dfs�Լ��� ��� �� �ּҰ�
            // ��������� ��λ��� ������ �� ���� ���� residual�� ��
            int df = dfs(next, dest, min(c[curr][next]-f[curr][next], flow));
            // ���� ��ΰ� �ִٸ�, ������ df��ŭ �긮�� ����
            if(df > 0){
                f[curr][next] += df;
                f[next][curr] -= df;
                return df;
            }
        }
    }
    // ���� ��θ� ã�� ����: ���� 0 �긲
    return 0;
}
 
 
 
int main(){
    // �׷��� ���� �Է¹ޱ�
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int team;
        scanf("%d", &team);
        if(team == 1){
            c[S][i] = INF;
            adj[S].push_back(i);
            adj[i].push_back(S);
        }
        else if(team == 2){
            c[i][E] = INF;
            adj[i].push_back(E);
            adj[E].push_back(i);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &c[i][j]);
            if(i != j) adj[i].push_back(j);
        }
    }
 
    // ��� �˰��� ����
    int total = 0;
    // ���� �׷����� �����Ͽ� ��ũ�� ���� ������ ���� �ݺ�
    while(bfs()){
        fill(work, work+MAX_V, 0);
        // ���� ����(blocking flow) ���ϱ�
        while(1){
            int flow = dfs(S, E, INF); // dfs�� ����� �� ��θ� ã��
            if(flow == 0) break; // �� �̻� ��ΰ� ������ ����
            total += flow; // �� ������ �̹��� ���� ���� ����
        }
    }
    printf("%d\n", total); // ������ ������ �ּ� �� ���
 
    // �� ������ ���� ����� �Ǵ��ϱ� ���� �ҽ������� ���ް��ɼ� �Ǻ�
    bool visited[MAX_V] = {false};
    visited[S] = true;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next: adj[curr]){
            // ���� �뷮�� �����ִ� �������� �̿�
            if(!visited[next] && c[curr][next]-f[curr][next] > 0){
                visited[next] = true;
                Q.push(next);
            }
        }
    }
 
    // A������ ���� �����: �ҽ����� ���� ����
    for(int i=0; i<N; i++)
        if(visited[i]) printf("%d ", i+1);
    puts("");
    // B������ ���� �����: �ҽ����� ���� �Ұ���
    for(int i=0; i<N; i++)
        if(!visited[i]) printf("%d ", i+1);
    puts("");
}


