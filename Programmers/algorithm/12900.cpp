#include <string>
#include <vector>
// 2 * n 타일링
// DP

using namespace std;

int cache[60'001];
int solution(int n) {
    cache[1] = 1;
    cache[2] = 2;
    for(int i = 3; i <= n; ++i){
        cache[i] = (cache[i-1] + cache[i-2]) % 1'000'000'007;
    }
    return cache[n];
}