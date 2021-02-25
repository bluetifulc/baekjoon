#include <cstdio>
#define MOD 1'000'000'003
// DP
int dp[1001][1001];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0; i <= n; ++i){
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= k; ++j){
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }
    printf("%d\n", ((dp[n-1][k] + dp[n-3][k-1]) % MOD));
    
    return 0;
}