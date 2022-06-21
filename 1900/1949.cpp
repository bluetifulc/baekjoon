#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
// 우수 마을
// Tree-DP

int n, resident[10'001];
int cache[10'001][2];
bool visited[10'001];

vector<int> adj[10'001];

void solve(int cur){
    visited[cur] = true;

    cache[cur][0] = 0;
    cache[cur][1] = resident[cur];

    for(int next: adj[cur]){
        if(visited[next])
            continue;
        solve(next);
        cache[cur][0] += max(cache[next][0], cache[next][1]);
        cache[cur][1] += cache[next][0];
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &resident[i]);
    }
    for(int i = 0; i < n-1; ++i){
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    printf("%d\n", max(cache[1][0], cache[1][1]));

    return 0;
}