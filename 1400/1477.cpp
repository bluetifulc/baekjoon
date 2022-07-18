#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
// 휴게소 세우기
// Parametric-Search (Binary Search)

int main(){
    int n,m,l;
    vector<int> rest;
    scanf("%d %d %d", &n, &m, &l);
    for(int i = 0; i < n; ++i){
        int u;
        scanf("%d", &u);
        rest.push_back(u);
    }
    rest.push_back(0);
    rest.push_back(l);
    sort(rest.begin(), rest.end());

    int lo = 1, hi = l-1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int cnt = 0;
        for(int i = 1; i < n+2; ++i){
            int cur = rest[i] - rest[i-1];
            cnt += (cur / mid);
            if(cur % mid == 0)
                --cnt;
        }
        if(cnt > m){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d\n", lo);

    return 0;
}