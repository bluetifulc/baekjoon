#include <cstdio>
// 타일 채우기
// DP

int main(){
    int n, cache[31] = { 0, };
    scanf("%d", &n);
    
    cache[0] = 1;
    cache[2] = 3;

    if(n % 2 == 1){
        printf("0\n");
        return 0;
    }

    for(int i = 4; i <= n; ++i){
        cache[i] = 3 * cache[i-2];
        for(int j = 4; j <= i; j+=2){
            cache[i] += 2 * cache[i-j];
        }
    }
    printf("%d\n", cache[n]);

    return 0;
}