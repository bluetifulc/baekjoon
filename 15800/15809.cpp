#include <cstdio>
#include <vector>
#include <algorithm>
// 전국시대
// Disjoint-set
using namespace std;

int p[100'001];
int army[100'001];

int find(int a){
    if(p[a] == -1) return a;
    return find(p[a]);
}

void ally(int a, int b){
    a = find(a);
    b = find(b);
    p[b] = a;
    army[a] += army[b];
}

void fight(int a, int b){
    a = find(a);
    b = find(b);
    if(army[a] == army[b]){
        p[a] = -1;
        p[b] = -1;
        army[a] = 0;
        army[b] = 0;
        return;
    }
    if(army[a] > army[b]){
        p[b] = a;
        army[a] -= army[b];
    }else{
        p[a] = b;
        army[b] -= army[a];
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&army[i]);
        p[i] = -1;
    }
    for(int i = 0; i < m; ++i){
        int o,p,q;
        scanf("%d %d %d", &o, &p, &q);
        if(o == 1){
            ally(p,q);
        }else{
            fight(p,q);
        }
    }
    vector<int> result;
    for(int i = 1; i <= n; ++i){
        if(find(i) == i && army[i] != 0){
            result.push_back(army[i]);
        }
    }
    sort(result.begin(), result.end());
    printf("%d\n", result.size());
    for(int v: result){
        printf("%d ", v);
    }
    printf("\n");

    return 0;
}