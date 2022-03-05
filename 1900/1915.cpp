#include <cstdio>
// 1915 가장 큰 정사각형
// DP, Ad-hoc
inline int min(int a, int b){ return a > b ? b : a; }
inline int max(int a, int b){ return a > b ? a : b; }

int dp[1002][1002];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%1d", &dp[i][j]);
		}
	}
	int result = 0;

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(dp[i][j])
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
			result = max(result, dp[i][j]);
		}
	}
	printf("%d\n", result*result);

	return 0;
}