#include <cstdio>
// 14864 줄서기
// ad-hoc
int main(){
	int n, m, count[100'001] = {0,};
	bool visited[100'001] = {0,};
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i){
		count[i] = i;
	}
	for(int i = 0; i < m; ++i){
		int u,v;
		scanf("%d %d", &u, &v);
		++count[u];
		--count[v];
	}
	for(int i = 1; i <= n; ++i){
		if(visited[count[i]]){
			printf("-1\n");
			return 0;
		}
		visited[count[i]] = true;
	}

	for(int i = 1; i <= n; ++i){
		printf("%d ", count[i]);
	}
	printf("\n");

	return 0;
}