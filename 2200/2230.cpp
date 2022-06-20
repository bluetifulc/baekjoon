#include <cstdio>
#include <algorithm>
// 수 고르기
// Two-Pointer

int main(){
    int n;
    long long m, num[100'001] = { 0, };
    scanf("%d %lld", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%lld", &num[i]);
    }
    std::sort(num, num+n);

    int lo = 0, hi = 0;
    long long result = 1e27;
    while(lo < n && hi < n){
        long long cur = num[hi] - num[lo];
        if(cur >= m && cur < result){
            result = cur;
        }
        if(cur >= m){
            if(lo == hi){
                ++hi;
            }else{
                ++lo;
            }
        }else{
            ++hi;
        }
    }
    printf("%lld\n", result);

    return 0;
}