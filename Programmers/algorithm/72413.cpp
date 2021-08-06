#include <string>
#include <vector>
#include <cstring>
using namespace std;
// 합승 택시 요금
// Floyd-Warshall
const int INF = 123456789;
int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i = 1; i <= n; ++i){
        memset(dist[i], INF, sizeof(dist[i]));
        dist[i][i] = 0;
    }
    for(int i = 0; i < fares.size(); ++i){
        int u = fares[i][0], v = fares[i][1], w = fares[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        int sum = dist[s][i] + dist[i][a] + dist[i][b];
        if(answer > sum) answer = sum;
    }
    return answer;
}