#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
int n,m;
int parent[50'001][17];
int depth[50'001];
std::vector<int> adj[50'001];
void dfs(int cur){
    for(int next: adj[cur]){
        if(depth[next] == -1){
            parent[next][0] = cur;
            depth[next] = depth[cur]+1;
            dfs(next);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n-1; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::memset(parent,-1,sizeof(parent));
    std::fill(depth,depth+n,-1);
    depth[0] = 0;
    dfs(0);
    for(int j = 0; j < 16; ++j){
        for(int i = 1; i < n; ++i){
            if(parent[i][j] != -1){
                parent[i][j+1] = parent[parent[i][j]][j];
            }
        }   
    }
    scanf("%d",&m);
    for(int i = 0; i < m; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        if(depth[u] < depth[v]) std::swap(u,v);
        int diff = depth[u]-depth[v];
        for(int j = 0; diff; ++j){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if(u != v){
            for(int j =16; j >= 0; --j){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        printf("%d\n", u+1);
    }
    return 0;
}