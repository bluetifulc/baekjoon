#include <string>
#include <vector>
// DP
using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1'000'000'007;
    int answer = 0;
    int map[101][101] = { 0 , };
    int dp[101][101] = { 0 , };
    for(int i = 0; i < puddles.size(); ++i){
        map[puddles[i][1]-1][puddles[i][0]-1] = 1;
    }
    for(int i = 0; i < n; ++i){
        if(map[i][0] == 0) dp[i][0] = 1;
        else break;
    }
    for(int i = 0; i < m; ++i){
        if(map[0][i] == 0) dp[0][i] = 1;
        else break;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            if(map[i][j] == 1){
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    answer = dp[n-1][m-1];
    return answer;
}