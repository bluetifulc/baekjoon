#include <cstdio>
using namespace std;
// Brute Force, Back-Tracking
int n,m,result,oracle[7],num[7];
void solve(int idx){
    if(idx == n){
        bool checked[10] = { 0 ,};
        for(int i = 0; i < n; ++i){
            checked[num[i]] = true;
        }
        for(int i = 0; i < m; ++i){
            if(checked[oracle[i]] == false) return;
        }
        result++;
        return;
    }
    for(int i = 0; i <= 9; ++i){
        num[idx] = i;
        solve(idx+1);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i){
        scanf("%d",&oracle[i]);
    }
    solve(0);
    printf("%d\n", result);
    return 0;
}