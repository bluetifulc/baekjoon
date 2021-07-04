#include <iostream>
#include <queue>
#include <string>
// 두 동전
// BFS
using namespace std;
struct Coord{
    int ax,ay,bx,by;
    Coord(int a, int b,int c, int d){
        ay = a;
        ax = b;
        by = c;
        bx = d;
    }
    Coord(){
        Coord(-1,-1,-1,-1);
    }
};

int n,m;
bool check(int y, int x){
    if(y >= n || y < 0 || x >= m || x < 0) return false;
    return true;
}
int main(){
    int ax = -1, ay = -1, bx = -1, by = -1;
    queue<Coord> q;
    string map[20];
    bool visited[20][20][20][20] = { 0, };
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> map[i];
        for(int j = 0; j < m; ++j){
            if(map[i][j] == 'o'){
                if(ax==-1){
                    ay = i;
                    ax = j;
                }else{
                    by = i;
                    bx = j;
                }
            }
        }
    }
    q.push(Coord(ay,ax,by,bx));
    visited[ay][ax][by][bx] = true;
    int dir[4][2] = { 0,1, 0,-1, 1,0, -1,0 };
    int time = 0;
    bool flag = false;
    while(!q.empty()){
        int qSize = q.size();
        if(++time > 10) break;
        while(qSize--){
            Coord cur = q.front();
            // cout << "(" << cur.ay << "," << cur.ax << ","  << cur.by << ","  << cur.bx << ")\n";
            q.pop();
            for(int i = 0; i < 4; ++i){
                int nay = cur.ay+dir[i][0];
                int nax = cur.ax+dir[i][1];
                int nby = cur.by+dir[i][0];
                int nbx = cur.bx+dir[i][1];
                bool checkA = check(nay,nax);
                bool checkB = check(nby,nbx);
                if((checkA && !checkB) || (!checkA && checkB)){
                    flag = true;
                    break;
                }
                if(!checkA || !checkB) continue;
                if(map[nay][nax] == '#'){
                    nay -= dir[i][0];
                    nax -= dir[i][1];
                }
                if(map[nby][nbx] == '#'){
                    nby -= dir[i][0];
                    nbx -= dir[i][1];
                }
                if(!visited[nay][nax][nby][nbx]){
                    visited[nay][nax][nby][nbx] = true;
                    q.push(Coord(nay,nax,nby,nbx));
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag) cout << time << endl;
    else cout << -1 << endl;
    return 0;
}