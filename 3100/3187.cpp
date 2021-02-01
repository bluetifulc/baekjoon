#include <iostream>
#include <string>
#include <queue>
using namespace std;
// BFS
int main(){
    int n,m;
    int dm[4][2] = { 0,1, 0,-1, 1,0 ,-1,0 };
    bool visited[251][251] = { 0 , };
    string map[251];
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> map[i];
    }
    int totalV = 0, totalK = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] && map[i][j] != '#'){
                int v = 0, k = 0;
                visited[i][j] = true;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int y = q.front().first, x = q.front().second;
                    q.pop();
                    if(map[y][x] == 'k') k++;
                    else if(map[y][x] == 'v') v++;
                    for(int h = 0; h < 4; ++h){
                        int dy = y+dm[h][0], dx = x+dm[h][1];
                        if(dy >= 0 && dx >= 0 && dy < n && dx < m && !visited[dy][dx] && map[dy][dx] != '#'){
                            q.push(make_pair(dy,dx));
                            visited[dy][dx] = true;
                        }
                    }
                }
                if(k > v) totalK += k;
                else totalV += v;
            }
        }
    }
    cout << totalK << " " << totalV << endl;
    return 0;
}