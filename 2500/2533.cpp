#include <cstdio>
#include <vector>
#include <algorithm>
#define INF -123456789
#define M 1'000'001
// 2533 사회망 서비스
// Tree-DP

int n, cache[M][2];
bool visited[M];
std::vector<int> adj[M];

void dfs(int cur){
    visited[cur]=true;

    cache[cur][0]=0;
    cache[cur][1]=1;

    for(int next: adj[cur]){
        if(visited[next])
			continue;
        dfs(next);
        cache[cur][0] += cache[next][1];
        cache[cur][1] += std::min(cache[next][0], cache[next][1]);
    }

}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i < M; ++i){
		cache[i][0] = INF;
		cache[i][1] = INF;
	}
	dfs(1);
	printf("%d\n", std::min(cache[1][0], cache[1][1]));
	return 0;
}