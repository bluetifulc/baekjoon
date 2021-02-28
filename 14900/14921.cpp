#include <cstdio>
// Two-Pointer
inline int abs(int a){ return ( a > 0 ? a : -a); }
int main(){
    int n,liquid[100'001];
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&liquid[i]);
    }
    int lo = 0, hi = n-1,result = 2e9+1;
    while(lo < hi){
        int sum = liquid[lo] + liquid[hi];
        if(abs(sum) < abs(result)) result = sum;
        if(sum > 0) hi--;
        else lo++;
    }
    printf("%d\n", result);
    return 0;
}