#include <cstdio>
// 동전
// DP (Knapsack)
int n, k, coin[20];
long long cache[10'001][20];

long long dp(int money, int idx){
    if(idx == n){
        if(money == 0) return 1;
        else return 0;
    }
    long long &ref = cache[money][idx];
    if(ref != -1) return ref;
    ref = 0;
    for(int i = 0; money-i*coin[idx] >= 0; ++i){
        ref += dp(money-i*coin[idx], idx+1);
    }
    return ref;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i <= 10'000; ++i){
            for(int j = 0; j < 20; ++j){
                cache[i][j] = -1;
            }
        }
        for(int i = 0; i < n; ++i){
            scanf("%d",&coin[i]);
        }
        scanf("%d",&k);
        printf("%lld\n", dp(k,0));
    }

    return 0;
}