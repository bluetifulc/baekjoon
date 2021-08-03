#include <iostream>
#include <string>
#include <queue>
// 벽 부수고 이동하기 3
// BFS
using namespace std;

int n,m,k;
string map[1'001];
bool visited[1'001][1'001][2][11];
int dm[4][2] = { 0,1, 0,-1, 1,0, -1,0 };

struct coord{
    int y,x,isDay,wall;
    coord(int y, int x,int isDay, int wall)
        :y(y), x(x), isDay(isDay), wall(wall){};
}; 

int main(){
    queue<coord> q;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        cin >> map[i];
    }
    int time = 0;
    bool flag = false;
    q.push(coord(0,0,0,0));
    visited[0][0][0][0] = true;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            coord cur = q.front();
            q.pop();
            if(cur.y == n-1 && cur.x == m-1){
                flag = true;
                break;
            }
            // printf("%d # %d %d, %d\n",time, cur.y,cur.x,cur.wall);
            int nday = cur.isDay == 0 ? 1 : 0;
            for(int i = 0; i < 4; ++i){
                int ny = cur.y+dm[i][0], nx = cur.x+dm[i][1];
                if(ny >= 0 && nx >= 0 && ny < n && nx < m){
                    if(map[ny][nx] == '0' && !visited[ny][nx][nday][cur.wall]){
                        visited[ny][nx][nday][cur.wall] = true;
                        q.push(coord(ny,nx,nday,cur.wall));
                    }else if(time % 2 == 0 && cur.wall+1 <= k && !visited[ny][nx][nday][cur.wall+1]){
                        visited[ny][nx][nday][cur.wall+1] = true;
                        q.push(coord(ny,nx,nday,cur.wall+1));
                    }
                }
            }
            if(!visited[cur.y][cur.x][nday][cur.wall]){
                visited[cur.y][cur.x][nday][cur.wall] = true;
                q.push(coord(cur.y,cur.x, nday, cur.wall));
            }

        }
        if(flag) break;
        ++time;
    }
    if(flag) printf("%d\n", time+1);
    else printf("-1\n");
    return 0;
}