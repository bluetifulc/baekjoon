#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
// BFS
inline int abs(int a){return (a > 0 ? a : -a);}
int main(){
    int n,l,r,map[51][51];
    int dm[4][2] = {0,1,1,0,-1,0,0,-1};
    scanf("%d%d%d",&n,&l,&r);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d",&map[i][j]);
        }
    }
    int result = 0;
    while(true){
        bool visited[51][51] = {0,};
        bool flag = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(!visited[i][j]){
                    visited[i][j] = true;
                    vector<pair<int,int>> points;
                    queue<pair<int,int>> q;
                    int sum = map[i][j];
                    q.push(make_pair(i,j));
                    points.push_back(make_pair(i,j));
                    while(!q.empty()){
                        int y = q.front().first, x = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; ++k){
                            int dy = y+dm[k][0], dx = x+dm[k][1];
                            if(dy >= 0 && dx >= 0 && dy < n && dx < n
                                && !visited[dy][dx]
                                && l <= abs(map[dy][dx]-map[y][x])
                                && abs(map[dy][dx]-map[y][x]) <= r
                            ){
                                visited[dy][dx] = true;
                                sum += map[dy][dx];
                                points.push_back(make_pair(dy,dx));
                                q.push(make_pair(dy,dx));
                            }
                        }
                    }
                    if(points.size() >= 2) flag = true;
                    sum /= points.size();
                    for(auto& p: points){
                        map[p.first][p.second] = sum;
                    }
                }
            }
        }
        if(flag) result++;
        else break;
    }
    printf("%d\n",result);
    return 0;
}