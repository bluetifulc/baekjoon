#include <cstdio>
// DP
inline int max(int a, int b){ return a > b ? a : b; }
int dp[1'001];
int main(){
    int n,matrix[1'001];
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&matrix[i]);
        dp[i] = 1;
    }
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(matrix[j] < matrix[i]){
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
    }
    int result = 0;
    for(int i = 0; i < n; ++i){
        result = max(result, dp[i]);
    }
    printf("%d\n",result);

    return 0;
}