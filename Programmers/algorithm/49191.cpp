#include <string>
#include <vector>
#define INF 123456789
using namespace std;

int solution(int n, vector<vector<int>> result) {
    int player[101][101] = {0,};
    int answer = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            player[i][j] = INF;
        }
        player[i][i] = 0;
    }
    for(int i = 0; i < result.size(); ++i){
        player[result[i][0]][result[i][1]] = 1;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(player[i][j] > player[i][k] + player[k][j])
                    player[i][j] = player[i][k] + player[k][j];
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        bool flag = true;
        for(int j = 1; j <= n; ++j){
            if(player[i][j] == INF && player[j][i] == INF){
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}