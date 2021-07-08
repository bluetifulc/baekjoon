#include <iostream>
#include <string>
#include <vector>
#include <queue>
// 경주로 건설
// Dijkstra
using namespace std;

int dist[25][25][4];
int dm[4][2] = { 1,0, -1,0, 0,1, 0,-1 };

struct coord{
    int y,x,dir,cost;
    coord(int y, int x, int dir, int cost)
        :x(x), y(y), dir(dir), cost(cost){}

    bool operator>(const coord& right) const{
        return cost > right.cost;
    }
};
int solution(vector<vector<int>> board) {
    int answer = 123456789;
    int my = board.size();
    int mx = board[0].size();
    priority_queue<coord, vector<coord>, greater<coord>> pq;
    for(int i = 0; i < my; ++i){
        for(int j = 0; j < mx; ++j){
            for(int k = 0; k < 4; ++k){
                dist[i][j][k] = 123456789;
            }
        }
    }
    dist[0][0][0] = 0;
    dist[0][0][1] = 0;
    dist[0][0][2] = 0;
    dist[0][0][3] = 0;
    pq.push(coord(0,0,0,0));
    pq.push(coord(0,0,1,0));
    pq.push(coord(0,0,2,0));
    pq.push(coord(0,0,3,0));
    while(!pq.empty()){
        coord cur = pq.top();
        pq.pop();
        int y = cur.y;
        int x = cur.x;
        int dir = cur.dir;
        int cost = cur.cost;
        for(int i = 0; i < 4; ++i){
            int ny = y + dm[i][0], nx = x + dm[i][1];
            if(ny >= my || nx >= mx || ny < 0 || nx < 0 || board[ny][nx]==1) continue;
            int nCost = cost;
            if(dir == i) nCost += 100;
            else nCost += 600;
            if(dist[ny][nx][i] > nCost){
                dist[ny][nx][i] = nCost;
                pq.push(coord(ny,nx,i,nCost));
            }
        }
    }
    for(int i = 0; i < 4; ++i){
        answer = min(answer, dist[my-1][mx-1][i]);
    }
    return answer;
}

int main(){
    vector<vector<int>> board = {{0,0,0},{0,0,0},{0,0,0}};
    cout << solution(board) << endl;
    return 0;
}