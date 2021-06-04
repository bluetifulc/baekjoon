#include <iostream>
#include <vector>
using namespace std;

bool visited[101];
vector<int> adj[101];
void dfs(int cur){
    cout << cur << " ";
    visited[cur] = true;
    for(int next: adj[cur]){
        if(!visited[next])
            dfs(next);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            adj[i].clear();
            visited[i] = false;
        }
        for(int i = 0; i < m; ++i){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        cout << endl;
    }

}