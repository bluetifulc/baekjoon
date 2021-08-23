#include <cstdio>
#include <vector>
#include <algorithm>
// 당근 훔쳐 먹기
// Greedy, Math
using namespace std;

int main(){
    int n, t;
    vector<pair<long long, long long>> carrots;
    long long result = 0;
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; ++i){
        int w,p;
        scanf("%d %d", &w, &p);
        carrots.push_back({p,w});
    }
    sort(carrots.begin(), carrots.end());
    for(int i = 0; i < n; ++i){
        result += carrots[i].second + carrots[i].first * (t-n+i);
    }
    printf("%lld\n", result);
    return 0;
}