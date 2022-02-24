#include <cstdio>
// 2617 구슬 찾기
// Floyd-Warshall
int main(){
	int n,m,adj[100][100];
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			adj[i][j] = 10000;
		}
	}
	for(int i = 0; i < m; ++i){
		int u,v;
		scanf("%d %d", &u, &v);
		adj[u][v] = 1;
	}

	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][j] > adj[i][k] + adj[k][j]){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}

	bool isChecked[100] = {0,};
	int result = 0;

	for(int i = 1; i <= n; ++i){
		int tmp = 0;
		for(int j = 1; j <= n; ++j){
			if(i != j && adj[i][j] != 10000){
				++tmp;
			}
		}
		if(tmp > n/2){
			++result;
			isChecked[i] = true;
			continue;
		}

		tmp = 0;
		for(int j = 1; j <= n; ++j){
			if(i != j && adj[j][i] != 10000){
				++tmp;
			}
		}
		if(tmp > n/2){
			++result;
			isChecked[i] = true;
			continue;
		}
	}
	printf("%d\n",result);
	return 0;
}