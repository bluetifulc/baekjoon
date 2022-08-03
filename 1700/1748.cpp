#include <cstdio>
// 수 이어 쓰기 1
// Implementation

int main(){
    int n, result = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i*=10){
        result += n - i + 1;
    }    
    printf("%d\n", result);
    return 0;
}
