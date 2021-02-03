#include <cstdio>
#include <cstring>
// Union-Find
int n,m;
int parent[100'001];
long long dist[100'001];
int find(int a){
    if(parent[a] == -1) return a;
    int origin = find(parent[a]);
    dist[a] += dist[parent[a]];
    return parent[a] = origin;
}
void merge(int a,int b,int diff){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;
    parent[pb] = pa;
    dist[pb] = dist[a]+diff - dist[b];
}
int main(){
    scanf("%d%d",&n,&m);
    while(true){
        if(n == 0 && m == 0) break;
        for(int i = 0; i <= n; ++i){
            parent[i] = -1;
            dist[i] = 0;
        }
        for(int i = 0; i < m; ++i){
            char oper;
            int a,b,w;
            scanf(" %c", &oper);
            if(oper == '!'){
                scanf("%d%d%d",&a,&b,&w);
                merge(a,b,w);
            }else{
                scanf("%d%d",&a,&b);
                if(find(a) != find(b)){
                    printf("UNKNOWN\n");
                }else{
                    printf("%lld\n", dist[b]-dist[a]);
                }
            }

        }
        scanf("%d%d",&n,&m);
    }
    return 0;
}