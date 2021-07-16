#include <iostream>
#include <queue>
// 학교 탐방하기
// MST ( Kruskal )
using namespace std;
struct road{
    int start,end,cost;
    road(int start, int end, int cost)
    :start(start), end(end), cost(cost){};
    bool operator<(const road& right) const{
        return cost<right.cost;
    }
    bool operator>(const road& right) const{
        return cost>right.cost;
    }
};

int p[1'001];
int find(int a){
    if(p[a] == -1) return a;
    return p[a] = find(p[a]);
}
bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    p[b] = a;
    return true;
}
int main(){
    int n,m;
    priority_queue<road, vector<road>, greater<road>> gpq;
    priority_queue<road> lpq;
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m+1; ++i){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        gpq.push(road(u,v,1-w));
        lpq.push(road(u,v,1-w));
    }
    int maxi = 0, mini = 0, cnt = 0;
    for(int i = 0; i <= n; ++i){
        p[i] = -1;
    }
    while(!gpq.empty()){
        if(merge(gpq.top().start, gpq.top().end)){
            mini += gpq.top().cost;
            if(++cnt == n) break;
        }
        gpq.pop();
    }
    for(int i = 0; i <= n; ++i){
        p[i] = -1;
    }
    cnt = 0;
    while(!lpq.empty()){
        if(merge(lpq.top().start, lpq.top().end)){
            maxi += lpq.top().cost;
            if(++cnt == n) break;
        }
        lpq.pop();
    }
    printf("%d\n", maxi*maxi-mini*mini);
    return 0;
}