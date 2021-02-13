#include <cstdio>
#include <vector>
using namespace std;
// Simulation + Back-Tracking
vector<pair<int,int>> blank;
int board[9][9];
bool rows[9][9],cols[9][9],box[9][9];
bool flag;

void solve(int idx){
    if(idx >= blank.size()){
        flag = true;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
        return;
    }
    bool isntCandidate[10] = { 0 , };
    int y = blank[idx].first, x = blank[idx].second;
    for(int i = 1; i <= 9; ++i){
        if(rows[y][i] || cols[x][i] || box[y-(y%3)+x/3][i]){
            isntCandidate[i] = true;
        }
    }
    for(int i = 1; i <= 9; ++i){
        if(isntCandidate[i]) continue;
        rows[y][i] = true;
        cols[x][i] = true;
        box[y-(y%3)+(x/3)][i] = true;
        board[y][x] = i;

        solve(idx+1);
        if(flag) return;
        rows[y][i] = false;
        cols[x][i] = false;
        box[y-(y%3)+(x/3)][i] = false;
        board[y][x] = 0;
    }

}

int main(){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            scanf("%d",&board[i][j]);
            if(board[i][j] == 0) blank.push_back(make_pair(i,j));
            else{
                rows[i][board[i][j]] = true;
                cols[j][board[i][j]] = true;
                box[i-(i%3)+(j/3)][board[i][j]] = true;
            }
        }
    }
    solve(0);
    return 0;
}