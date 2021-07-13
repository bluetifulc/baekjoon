#include <iostream>
#include <string>
// 나의 인생에는 수학과 함께
// DFS
using namespace std;
inline int max(int a,int b){ return ( a > b ? a : b); }
inline int min(int a,int b){ return ( a > b ? b : a); }
char map[5][5];
int n, mini = 123456789, maxi = -123456789;
int calc(int left, char oper, int right){
    if(oper == '+') return left + right;
    if(oper == '-') return left - right;
    return left * right;
}
void dfs(int y,int x, int cost){
    if(y == n-1 && x == n-1){
        maxi = max(maxi, cost);
        mini = min(mini, cost);
        return;
    }
    if(y + 1 < n){ // 아래로 이동 
        if(y + 2 < n){
            dfs(y+2,x, calc(cost, map[y+1][x], map[y+2][x]-'0'));
        }
        if(x + 1 < n){
            dfs(y+1,x+1, calc(cost, map[y+1][x], map[y+1][x+1]-'0'));
        }
    }
    if(x + 1 < n){ // 오른쪽으로 이동 
        if(x + 2 < n){
            dfs(y,x+2, calc(cost, map[y][x+1], map[y][x+2]-'0'));
        }
        if(y + 1 < n){
            dfs(y+1,x+1, calc(cost, map[y][x+1], map[y+1][x+1]-'0'));
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf(" %c", &map[i][j]);
        }
    }
    dfs(0,0, map[0][0]-'0');
    cout << maxi << endl << mini << endl;
    return 0;
}