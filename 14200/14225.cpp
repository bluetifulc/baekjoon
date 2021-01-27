#include <cstdio>
#include <set>
using namespace std;

int n,nums[20];
set<int> can;
void solve(int idx, int sum){
    if(idx == n){
        can.insert(sum);
        return;
    }
    solve(idx+1, sum);
    solve(idx+1, sum + nums[idx]);
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&nums[i]);
    }
    solve(0,0);
    for(int result = 1;;++result){
        if(can.count(result) == 0){
            printf("%d\n", result);
            break;
        }
    }
    return 0;
}