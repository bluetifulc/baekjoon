#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int parent[50'001][17];
int depth[50'001],dist[50'001];
std::vector<pair<int,int>> adj[50'001];
void dfs(int cur){
    for(auto p: adj[cur]){
        int next = p.first, w = p.second;
        if(depth[next] == -1){
            depth[next] = depth[cur]+1;
            dist[next] = dist[cur]+w;
            parent[next][0] = cur;
            dfs(next);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n-1; ++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    memset(parent,-1,sizeof(parent));
    fill(depth,depth+n,-1);
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
        int a = u, b = v;
        if(depth[u] < depth[v]) swap(u,v);
        int diff = depth[u] - depth[v];
        for(int j = 0; diff; ++j){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if(u != v){
            for(int j = 16; j >= 0; --j){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        int result = dist[a]+dist[b]-2*dist[u];
        printf("%d\n",result);
    }
    return 0;
}