#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
inline int abs(int x){ return x > 0 ? x : -x; }
int N, result, col[16];
bool map[12][12];
bool check(int x){
    for(int i = 0 ; i < x; ++i){
        if(col[i] == col[x]) return false;
        if(abs(col[i]-col[x]) == abs(i-x)) return false;
    }
    return true;
}
void queen(int x){
    if(x == N){
        ++result;
        return;
    }
    for(int i = 0; i < N; ++i){
        col[x] = i;
        if(check(x)){
            queen(x+1);
        }else{
            col[x] = 0;
        }
    }
    col[x] = 0;
}
int solution(int n) {
    N = n;
    queen(0);
    return result;
}
int main(){
    scanf("%d",&N);
    queen(0);
    printf("%d\n",result);
    return 0;
}