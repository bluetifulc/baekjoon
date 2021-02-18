#include <iostream>
#include <string>
using namespace std;
// Brute-Force Graph
int main(){
    int r,c, total = 0;
    string map[10];
    int dm[4][2] = { -1,0, 0,1, 1,0, 0,-1 };
    scanf("%d%d",&r,&c);
    for(int i = 0; i < r; ++i){
        cin >> map[i];
    }
    bool flag = false;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(map[i][j] != '.') continue;
            int cnt = 0;
            for(int k = 0; k < 4; ++k){
                int dy = i + dm[k][0], dx = j + dm[k][1];
                if(dy >= 0 && dx >= 0 && dy < r && dx < c && map[dy][dx] == '.'){
                    cnt++;
                }
            }
            if(cnt <= 1){
                flag = true;
                break;
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(!flag) printf("0\n");
    else printf("1\n");
    return 0;
}

