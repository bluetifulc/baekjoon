#include <cstdio>

int cctv[8][2],dir[8] ,cnt;
int n,m,map[8][8], checkmap[8][8];
int result = 123456789;
int dm[4][2] = {0,1,1,0,0,-1,-1,0};
void check(int y, int x, int d){
    d %= 4;
    int dy = y, dx = x;
    while(true){
        dy = dy+dm[d][0], dx = dx+dm[d][1];
        if(dy >= 0 && dx >= 0 && dy < n && dx < m && checkmap[dy][dx] != 6){
            checkmap[dy][dx] = 7;
        }else{
            break;
        }
    }
}
void solve(int idx){
    if(idx == cnt){ // count 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                checkmap[i][j] = map[i][j];
            }
        }
        for(int i = 0; i < cnt; ++i){
            int ccnum = map[cctv[i][0]][cctv[i][1]];
            int d = dir[i];
            if(ccnum == 1){
                check(cctv[i][0], cctv[i][1], d);
            }
            else if(ccnum == 2){
                check(cctv[i][0], cctv[i][1], d);
                check(cctv[i][0], cctv[i][1], d+2);
            }
            else if(ccnum == 3){
                check(cctv[i][0], cctv[i][1], d);
                check(cctv[i][0], cctv[i][1], d+1);
            }
            else if(ccnum == 4){
                check(cctv[i][0], cctv[i][1], d);
                check(cctv[i][0], cctv[i][1], d+1);
                check(cctv[i][0], cctv[i][1], d+2);
            }
            else if(ccnum == 5){
                check(cctv[i][0], cctv[i][1], 0);
                check(cctv[i][0], cctv[i][1], 1);
                check(cctv[i][0], cctv[i][1], 2);
                check(cctv[i][0], cctv[i][1], 3);
            }
        }
        int sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(checkmap[i][j] == 0){
                    sum++;
                }
            }
        }
        if( sum < result) result = sum;
        return;
    }

    for(int i = 0; i < 4; ++i){
        dir[idx] = i;
        solve(idx+1);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d",&map[i][j]);
            if(0 < map[i][j] && map[i][j] < 6){
                cctv[cnt][0] = i;
                cctv[cnt][1] = j;
                cnt++;
            }
        }
    }
    solve(0);
    printf("%d", result);
    return 0;
}