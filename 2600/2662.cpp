#include <cstdio>
// Top-Down DP + 悼利拌裙过 开眠利

inline int max(int a, int b){ return a > b ? a : b; }
int n,m;
int invest[21][302];
int dp[21][302];
int solve(int idx, int sum){
    if(idx > m){
        return 0;
    }
    int &ref = dp[idx][sum];
    if(ref != 0) return ref;
    for(int i = 0; sum+i <= n; ++i){
        ref = max(ref, invest[idx][i] + solve(idx+1, sum+i));
    }
    return ref;
}

void track(int idx, int sum){
    if(idx > m) return;
    for(int i = 0; sum+i <= n; ++i){
        if(solve(idx+1,sum+i)+invest[idx][i] == solve(idx,sum)){
            printf("%d ", i);
            track(idx+1,sum+i);
            return;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i){
        int w;
        scanf("%d",&w);
        for(int j = 1; j <= m; ++j){
            scanf("%d",&invest[j][i]);
        }
    }
    printf("%d\n",solve(1,0));
    track(1,0);
    printf("\n");
    return 0;
}