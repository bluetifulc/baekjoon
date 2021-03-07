#include <cstdio>
inline int min(int a,int b){ return a > b ? b : a; }
// DP
int n,hp[3],dp[61][61][61];
int damage[3] = { 1,3,9 };
int solve(int hpn,int hpm, int hpk){
    if(hpn <= 0 && hpm <= 0 && hpk <= 0) return 0;
    if(hpn < 0) hpn = 0;
    if(hpm < 0) hpm = 0;
    if(hpk < 0) hpk = 0;
    int &ref = dp[hpn][hpm][hpk];
    if(ref != 123456789) return ref;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                if(i == j || i == k || k == j) continue;
                ref = min(ref, 1+solve(hpn-damage[i],hpm-damage[j],hpk-damage[k]));
            }
        }
    }
    return ref;
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &hp[i]);
    }
    for(int i = 0; i <= 60; ++i){
        for(int j = 0; j <= 60; ++j){
            for(int k = 0; k <= 60; ++k){
                dp[i][j][k] = 123456789;
            }
        }
    }
    printf("%d\n",solve(hp[0],hp[1],hp[2]));
    return 0;
}