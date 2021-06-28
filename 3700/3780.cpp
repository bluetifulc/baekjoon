#include <cstdio>
// Disjoint-set
int p[20'001], len[20'001];
inline int abs(int a) { return ( a > 0 ? a : -a); }
int find(int a){
    if(p[a] == -1) return a;
    int par = find(p[a]);
    len[a] += len[p[a]];
    return p[a] = par;
}
void merge(int a, int b){
    p[a] = b;
    len[a] = abs(a-b)%1000;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i){ 
            p[i] = -1;
            len[i] = 0;
        }
        char oper;
        while(true){
            scanf(" %c", &oper);
            if(oper == 'O') break;
            if(oper == 'E'){
                int u;
                scanf("%d",&u);
                find(u);
                printf("%d\n", len[u]);
            }else{
                int u,v;
                scanf("%d %d",&u,&v);
                merge(u,v);
            }
        }        
    }
    return 0;
}