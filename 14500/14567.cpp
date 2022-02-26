#include <cstdio>
#include <queue>
#include <vector>
// 14567 선수과목
// Topological-Sort
int main(){
	int n,m,time[1001] = { 0, };
	int check[1001] = { 0, };
	std::vector<int> adj[1001];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		++check[v];
	}
	std::queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(check[i] == 0){
			q.push(i);
			time[i] = 1;
		}
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int next: adj[cur]){
			if(--check[next] <= 0){
				time[next] = time[cur]+1;
				q.push(next);
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		printf("%d ", time[i]);
	}
	printf("\n");

	return 0;
}