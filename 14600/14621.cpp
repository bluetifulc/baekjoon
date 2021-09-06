#include <cstdio>
#include <queue>
// 나만 안되는 연애
// MST 
using namespace std;
struct road{
    int u,v,w;
    road()
        :road(0,0,0){};
    road(int u, int v, int w)
        :u(u),v(v),w(w){};
};
bool operator>(const road& left, const road& right){
    return left.w > right.w;
}
int p[1001];
int n,m;
char univ[1001];
int find(int a){
    if(p[a] == -1) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    p[b] = a;
    return true;
}

int main(){
    priority_queue<road,vector<road>,greater<road>> pq;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; ++i){
        scanf(" %c", &univ[i]);
        p[i] = -1;
    }
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        pq.push(road(u,v,w));
    }
    int con = 1, cost = 0;
    while(!pq.empty()){
        road cur = pq.top();
        pq.pop();
        if(univ[cur.u] == univ[cur.v]) continue;
        if(merge(cur.u, cur.v)){
            cost += cur.w;
            if(++con == n) break;
        }
    }
    if(con == n) printf("%d\n", cost);
    else printf("-1\n");
    return 0;
}