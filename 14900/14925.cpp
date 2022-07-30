#include <cstdio>
// 목장 건설하기
// DP

inline int max(int a, int b){ return a > b ? a : b; }
inline int min(int a, int b){ return a > b ? b : a; }

int m,n,map[1'001][1'001];
int dp[1'001][1'001];
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    int result = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(map[i][j] != 0)
                continue;
            dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]))+1;
            result = max(result, dp[i][j]);
        }
    }
    printf("%d\n", result);
    return 0;
}
