#include <cstdio>
#include <algorithm>
using namespace std;
// 파일 합치기
// DP

int chapter[501], sum[501];
int dp[501][501];

int solve(int start, int end){
    if(start == end){
        return 0;
    }
    int& ref = dp[start][end];
    if(ref != -1){
        return ref;
    }
    ref = 123456789;
    for(int mid = start; mid < end; ++mid){
        
        ref = min(ref, solve(start, mid) + solve(mid+1, end) + sum[end] - sum[start-1]);
    }
    return ref;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        scanf("%d", &k);
        fill(&dp[0][0], &dp[500][501], -1);
        for(int i = 1; i <= k; ++i){
            scanf("%d", &chapter[i]);
            sum[i] = sum[i-1]+chapter[i];
        }
        printf("%d\n", solve(1, k));
    }

    return 0;
}