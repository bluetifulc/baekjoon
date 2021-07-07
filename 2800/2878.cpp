#include <iostream>
#include <queue>
#define LL long long
// 캔디캔디
// Greedy 
using namespace std;

int main(){
    int m,n;
    LL sum = 0;
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    scanf("%d%d",&m,&n);
    for(int i = 0; i < n; ++i){
        LL u;
        scanf("%lld", &u);
        pq.push(u);
        sum += u;
    }
    LL result = 0;
    sum -= m;
    for(int i = 0; i < n; ++i){
        LL cur = pq.top();
        pq.pop();
        cur = min(cur, sum / (n-i));
        result += cur*cur;
        sum -= cur;
    }
    printf("%lld\n", result);
    return 0;
}