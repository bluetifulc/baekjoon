#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
// Baaaaaaaaaduk2 (Easy)
// BruteForce, BFS

int n, m, map[21][21];
int dm[4][2] = { 0,1, 0,-1, 1,0, -1,0 };
bool visited[21][21] = { 0, };
vector<pair<int, int>> candidate;

int bfs(int sy, int sx){
    if(sy < 0 || sx < 0 || sy >= n || sx >= m || map[sy][sx] != 2){
        return 0;
    }
    queue<pair<int,int>> q;
    int cnt = 1;

    visited[sy][sx] = true;
    q.push(make_pair(sy, sx));
    bool flag = true;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y+dm[i][0], nx = x+dm[i][1];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m){
                if(map[ny][nx] == 2 && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push(make_pair(ny,nx));
                    cnt++;
                }else if(map[ny][nx] == 0){
                    flag = false;
                }
            }
        }
    }
    if(!flag)
        return 0;
    return cnt;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0){
                candidate.push_back(make_pair(i, j));
            }
        }
    }

    int result = 0;
    int csize = candidate.size();
    for(int i = 0; i < csize; ++i){
        for(int j = i+1; j < csize; ++j){
            map[candidate[i].first][candidate[i].second] = 1;
            map[candidate[j].first][candidate[j].second] = 1;
            memset(visited, false, sizeof(visited));
            int cur = 0;
            for(int k = 0; k < 4; ++k){
                int ny = candidate[i].first+dm[k][0], nx = candidate[i].second+dm[k][1];
                if(ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx] == 2 && !visited[ny][nx]){
                    cur += bfs(ny,nx);
                }
            }
            for(int k = 0; k < 4; ++k){
                int ny = candidate[j].first+dm[k][0], nx = candidate[j].second+dm[k][1];
                if(ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx] == 2 && !visited[ny][nx]){
                    cur += bfs(ny,nx);
                }
            }
            result = max(result, cur);
            map[candidate[i].first][candidate[i].second] = 0;
            map[candidate[j].first][candidate[j].second] = 0;
        }
    }
    printf("%d\n", result);
    return 0;
}