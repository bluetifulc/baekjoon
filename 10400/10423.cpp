#include <cstdio>
#include <queue>
using namespace std;
// 전기가 부족해
// MST

struct wire{
    int u,v,w;
};

struct compare{
    bool operator()(const wire& left, const wire& right){
        return left.w > right.w;
    }
};


bool generator[1'001];
int p[1'001];

int find(int a) {
    if(p[a] == a)
        return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    if(p[a] == p[b])
        return false;
    a = find(a);
    b = find(b);
    if(generator[a] && generator[b])
        return false;
    if(generator[a]){
        p[b] = a;
    }else{
        p[a] = b;
    }
    return true;
}

int main(){
    int n,m,k, count = 0, result = 0;
    priority_queue<wire, vector<wire>, compare> q;
    scanf("%d %d %d", &n, &m ,&k);
    for(int i = 1; i <= n; ++i){
        p[i] = i;
    }
    for(int i = 0; i < k; ++i){
        int u;
        scanf("%d", &u);
        generator[u] = true;
        p[u] = u;
        ++count;
    }
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        q.push({u,v,w});
    }

    while(!q.empty() && count < n){
        wire cur = q.top();
        q.pop();
        if(merge(cur.u, cur.v)){
            result += cur.w;
            ++count;
        }
    }
    printf("%d\n", result);

    return 0;
}