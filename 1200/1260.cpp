#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
// DFS와 BFS
// DFS, BFS
using namespace std;

int n,m,v;
bool visited[1'001];
vector<int> adj[1'001];

void dfs(int idx){
    printf("%d ", idx);
    for(int next: adj[idx]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
        }
    }
}

void bfs(int idx){
    queue<int> q;
    q.push(idx);
    while(!q.empty()){
        int cur = q.front();
        printf("%d ", cur);
        q.pop();
        for(int next:adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&v);
    for(int i = 0; i < m; ++i){
        int u,w;
        scanf("%d %d",&u,&w);
        adj[u].push_back(w);
        adj[w].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }
    visited[v] = true;
    dfs(v);
    printf("\n");
    for(int i = 1; i <= n; ++i){
        visited[i] = false;
    }
    visited[v] = true;
    bfs(v);
    printf("\n");
    return 0;
}