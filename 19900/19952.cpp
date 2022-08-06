#include <cstdio>
#include <set>
#include <queue>
using namespace std;
// 인성 문제 있어?
// BFS

struct coord{
    int y, x, f;
    coord(int y, int x, int f):y(y), x(x), f(f){}
};

int calc(int y, int x, int f){
    return f*20000 + y*200 + x;
}

int main(){
    int t;
    int dm[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
    scanf("%d", &t);
    while(t--){
        int h,w,o,f,ys,xs,ye,xe;
        int map[101][101] = { 0, };
        scanf("%d %d %d %d %d %d %d %d", &h, &w, &o, &f, &ys, &xs, &ye, &xe);
        for(int i = 0; i < o; ++i){
            int u,v,p;
            scanf("%d %d %d", &u, &v, &p);
            map[u][v] = p;
        }
        set<int> visited;
        queue<coord> q;
        bool flag = false;

        q.push(coord(ys,xs,f));
        visited.insert(calc(ys,xs,f));
        while(!q.empty()){
            int y = q.front().y, x = q.front().x, p = q.front().f;
            q.pop();
            if(y == ye && x == xe){
                flag = true;
                break;
            }
            if(p == 0){
                continue;
            }

            for(int i = 0; i < 4; ++i){
                int dy = y + dm[i][0], dx = x + dm[i][1];
                if(dy >= 1 && dx >= 1 && dy <= h && dx <= w && map[dy][dx] - map[y][x] <= p){
                    if(visited.find(calc(dy,dx,p-1)) == visited.end()){
                        q.push(coord(dy,dx,p-1));
                        visited.insert(calc(dy,dx,p-1));
                    }
                }
            }
        }

        if(flag){
            printf("잘했어!!\n");
        }else{
            printf("인성 문제있어??\n");
        }
    }

    return 0;
}
