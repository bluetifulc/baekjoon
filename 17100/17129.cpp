#include <queue>
#include <cstdio>
using namespace std;
//BFS
bool visited[3000][3000];
int map[3000][3000];
int dm[4][2] = { 0,1, 1,0, 0,-1, -1,0 };
int main(){
    int n,m;
    queue<pair<int,int>> q;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%1d",&map[i][j]);
            if(map[i][j] == 2){ 
                q.push(make_pair(i,j));
                visited[i][j] = true;
            }
        }
    }
    bool flag = false;
    int result = 0;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            int y = q.front().first, x = q.front().second;
            q.pop();
            if(map[y][x] >= 3){
                flag = true;
                break;
            }
            for(int i = 0; i < 4; ++i){
                int dy = y + dm[i][0], dx = x + dm[i][1];
                if(dy >= 0 && dx >= 0 && dy < n && dx < m){
                    if(!visited[dy][dx] && map[dy][dx] != 1){
                        q.push(make_pair(dy,dx));
                        visited[dy][dx] = true;
                    }
                }
            }
        }
        if(flag) break;
        result++;
    }
    if(flag){ 
        printf("TAK\n%d\n",result);
    }
    else printf("NIE");
    return 0;
}