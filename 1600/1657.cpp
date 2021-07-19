#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
// 두부 장수 장홍준
// DP using Bit-Field
using namespace std;
const int MOD = 9901;
const int M = 14;
const int price[5][5] = {
    { 10, 8, 7, 5, 1 },
    { 8, 6, 4, 3, 1},
    { 7, 4, 3, 2, 1},
    { 5, 3, 2, 2, 1},
    { 1, 1, 1, 1, 0}
};
string map[M];
int n,m,dp[M*M][1<<M];

int howmuch(char a, char b){
    if(a == 'F') a = 'E';
    if(b == 'F') b = 'E';
    return price[a-'A'][b-'A'];
}

int solve(int idx, int bit){
    if(idx == n*m && bit == 0) return 0;
    if(idx >= n*m) return -123456789;
    int &ref = dp[idx][bit];
    if(ref != -1) return ref;
    ref = -123456789;
    if((bit & 1) == 1) return ref = solve(idx+1, bit>>1);
    ref = max(ref, solve(idx+1, bit >> 1)); // 아무것도 안놓는 경우
    if(idx/m + 1 < n)
        ref = max(ref, howmuch(map[idx/m][idx%m], map[idx/m+1][idx%m]) 
                    + solve(idx+1, (1 << (m-1)) | (bit>>1))); // 세로로 2칸
    if((bit & 2) == 0 && idx%m != m-1 && idx+1 < n*m){ // 가로로 두칸
        ref = max(ref, howmuch(map[idx/m][idx%m], map[(idx+1)/m][(idx+1)%m]) 
                    + solve(idx+2, bit >> 2));
    }
    return ref;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> map[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(0,0) << endl;
    return 0;
}