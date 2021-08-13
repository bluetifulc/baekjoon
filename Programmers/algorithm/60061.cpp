#include <cstdio>
#include <string>
#include <vector>
// 기둥과 보 설치
// Simulation, Brute-Force
using namespace std;

int m;
int pillar[101][101] = { 0, }, ceiling[101][101] = { 0, };

bool check(){
    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= m; ++j){
            if(pillar[i][j] == 1){
                if(j == 0) continue; // 바닥
                if(pillar[i][j-1] == 1) continue; // 밑에 기둥
                if(i >= 1 && ceiling[i-1][j] == 1) continue; // 왼쪽 밑에 보
                if(i < m && ceiling[i][j] == 1) continue; // 오른쪽 밑에 보
                return false;
            }
        }
    }
    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= m; ++j){
            if(ceiling[i][j] == 1){
                if(pillar[i][j-1] == 1) continue; // 왼쪽에 기둥
                if(i < m && pillar[i+1][j-1] == 1) continue; // 오른쪽에 기둥
                if(i >= 1 && i < m && ceiling[i-1][j] == 1 && ceiling[i+1][j] == 1) continue; // 양쪽에 보
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    m = n;
    vector<vector<int>> answer;
    for(int i = 0; i < build_frame.size(); ++i){
        int x = build_frame[i][0], y = build_frame[i][1];
        int a = build_frame[i][2], b = build_frame[i][3];
        if(a == 0 && b == 1){ // 기둥설치
            pillar[x][y] = 1;
            if(!check()){
                pillar[x][y] = 0;
            }
        }
        if(a == 0 && b == 0){ // 기둥삭제
            pillar[x][y] = 0;
            if(!check()){
                pillar[x][y] = 1;
            }
        }
        if(a == 1 && b == 1){ // 보설치
            ceiling[x][y] = 1;
            if(!check()){
                ceiling[x][y] = 0;
            }
        }
        if(a == 1 && b == 0){ // 보삭제
            ceiling[x][y] = 0;
            if(!check()){
                ceiling[x][y] = 1;
            }
        }
    }
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            if(pillar[i][j] == 1) answer.push_back({i,j,0});
            if(ceiling[i][j] == 1) answer.push_back({i,j,1});
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> input = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1},{3,2,1,0}};
    vector<vector<int>> output = solution(5, input);
    for(int i = 0; i < output.size(); ++i){
        printf("%d %d %d\n",output[i][0], output[i][1], output[i][2]);
    }

}