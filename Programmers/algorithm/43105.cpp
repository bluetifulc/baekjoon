#include <string>
#include <vector>
// 정수삼각형
// DP

using namespace std;

inline int max(int a, int b){ return a > b ? a : b; }

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501] = { 0, };
    int tsize = triangle.size();
    
    dp[0][0] = triangle[0][0];
    if(tsize >= 2){
        dp[1][0] = dp[0][0] + triangle[1][0];
        dp[1][1] = dp[0][0] + triangle[1][1];
    }
    for(int i = 1; i < tsize; ++i){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for(int j = 1; j < i; ++j){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];  
        }
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    
    for(int i = 0; i < tsize; ++i){
        answer = max(answer, dp[tsize-1][i]);
    }
    
    return answer;
}