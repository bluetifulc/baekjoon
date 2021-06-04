#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];
int bfs(int cur, int dest){
    bool visited[101] = { 0, };
    int result = 0;
    queue<int> q;
    q.push(cur);
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            cur = q.front();
            q.pop();
            if(cur == dest) return result;
            for(int next: adj[cur]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        result++;
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; ++i){
            adj[i].clear();
        }
        for(int i = 0; i < m; ++i){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < k; ++i){
            int u,v;
            cin >> u >> v;
            cout << bfs(u,v)<< endl;
        }
    }

}