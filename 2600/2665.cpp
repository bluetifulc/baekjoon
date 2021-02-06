#include <cstdio>
#include <queue>
using namespace std;
// Daijkstra
struct point{
    int y,x,w;
    point(int a, int b,int c):y(a),x(b),w(c){}
    point():point(0,0,0){}
    bool operator>(const point& right) const{
        return w > right.w;
    }
};
int main(){
    int dm[4][2] = {0,1, 0,-1, 1,0, -1,0};
    int dist[51][51] = { 0, };
    int n,map[51][51] = { 0, };
    bool visited[51][51] = { 0,};
    priority_queue<point, vector<point>,greater<point>> pq;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int t;
            scanf("%1d",&map[i][j]);
            dist[i][j] = 123456789;
        }
    }
    pq.push(point(0,0,0));
    dist[0][0] = 0;
    while(!pq.empty()){
        int y,x,w;
        do{
            y = pq.top().y;
            x = pq.top().x;
            w = pq.top().w;
            pq.pop();
        }while(!pq.empty() && visited[y][x]);
        if(visited[y][x])break;
        if(y == n-1 && x == n-1) break;
        visited[y][x] = true;
        for(int i = 0; i < 4; ++i){
            int dy = y + dm[i][0], dx = x + dm[i][1];
            if(dy >= 0 && dx >= 0 && dy < n && dx < n){
                int dw = w;
                if(map[dy][dx] == 0) dw++;
                if(!visited[dy][dx] && dist[dy][dx] > dw){
                    dist[dy][dx] = dw;
                    pq.push(point(dy,dx,dw));
                }
            }
        }
    }
    printf("%d\n",dist[n-1][n-1]);
    return 0;
}