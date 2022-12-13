#include <string>
#include <vector>
// 파괴되지 않은 건물
// P-Sum

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int s[1002][1002] = {0,};
    int n = board.size(), m = board[0].size();
    for(auto& n: skill){
        int type=n[0],r1=n[1],c1=n[2],r2=n[3],c2=n[4],deg=n[5];
        if(type == 1){
            deg *= -1;
        }
        s[r1][c1]+=deg;
        s[r1][c2+1]-=deg;
        s[r2+1][c1]-=deg;
        s[r2+1][c2+1]+=deg;
    }
    int ps[1002][1002] = { 0, };
    for(int i = 0; i < n; ++i){
        ps[i][0] = s[i][0];
        for(int j = 1; j < m; ++j){
            ps[i][j] = ps[i][j-1] + s[i][j];
        }
    }
    
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ps[i][j] += ps[i-1][j];
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] + ps[i][j] >= 1){
                ++answer;
            }
        }
    }
    return answer;
}