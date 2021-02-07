#include <iostream>
#include <queue>
#include <string>
using namespace std;
// BFS + BitMasking
int pow(int a){
    if(a == 0) return 1;
    return 2*pow(a-1);
}
struct point{
    int y,x,w;
    point(int a,int b,int c):y(a),x(b),w(c){}
    point():point(0,0,0){}
};
int main(){
    int n,m,cnt=0;
    int dm[4][2] = {0,1, 0,-1, 1,0, -1,0};
    int fy,fx;
    bool visited[51][51][65] = { 0, };
    string map[51];
    queue<point> q;
    scanf("%d%d",&m,&n);
    for(int i = 0; i < n; ++i){
        cin >> map[i];
        for(int j = 0; j < m; ++j){
            if(map[i][j] == 'X'){
                map[i][j] = 'a'+cnt;
                cnt++;
            }
            else if(map[i][j] == 'S'){
                q.push(point(i,j,0));
                visited[i][j][0] = true;
            }
            else if(map[i][j] == 'E'){
                fy = i, fx = j;
            }
        }
    }
    bool flag = false;
    int result = 0;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            int y = q.front().y, x = q.front().x, w = q.front().w;
            q.pop();
            if(y == fy && x == fx && w == pow(cnt)-1){
                flag = true;
                break;
            }

            for(int i = 0; i < 4; ++i){
                int dy = y+dm[i][0], dx = x+dm[i][1];
                int dw = w;
                if(dy >= 0 && dx >= 0 && dy < n && dx < m){
                    if(map[dy][dx] == '#') continue;
                    if('a' <= map[dy][dx] && map[dy][dx] <= 'a'+cnt-1){
                        dw = dw | (1 << (map[dy][dx]-'a'));
                    }
                    if(!visited[dy][dx][dw]){
                        q.push(point(dy,dx,dw));
                        visited[dy][dx][dw] = true;
                    }
                }
            }
        }
        if(flag) break;
        result++;
    }
    printf("%d\n", result);
    return 0;
}