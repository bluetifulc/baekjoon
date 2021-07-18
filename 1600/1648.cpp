#include <cstdio>
#include <cstring>
// 격자판 채우기
// DP using Bit-Field
const int MOD = 9901;
const int M =  14;

int n,m,dp[M*M][1<<M];

int solve(int idx, int bit){
    if(idx == n*m && bit == 0){
        return 1;
    }
    if(idx >= n*m) return 0;
    int &ref = dp[idx][bit];
    if(ref != -1) return ref;
    if((bit & 1) == 1) return ref = (solve(idx+1, (bit>>1)) % MOD);
    ref = solve(idx+1, ((1 << (m-1))) | (bit >> 1));
    if((bit & 2) == 0 && (idx % m) != m-1){
        ref += solve(idx+2, bit >> 2);
    }
    return ref %= MOD;
}

int main(){
    scanf("%d %d",&n,&m);
    memset(dp,-1,sizeof(dp));
    printf("%d\n", solve(0,0));
    return 0;
}