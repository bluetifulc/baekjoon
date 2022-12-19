#include <string>
#include <vector>

// 모두 0으로 만들기
// DFS

inline int abs(int b){ return (b > 0 ? b : -1 * b); }
using namespace std;

long long answer;
bool visited[300'001];
vector<vector<int>> adj;

long long dfs(int cur, vector<int>& a){
    long long now = a[cur];
    visited[cur] = true;
    for(int next: adj[cur]){
        if(!visited[next]){
            long long w = dfs(next, a);
            answer += abs(w);
            now += w;
        }
    }
    return now;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    int n = a.size();
    adj.resize(n+1);
    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(0, a) == 0){
        return answer;
    }else{
        return -1;
    }
}