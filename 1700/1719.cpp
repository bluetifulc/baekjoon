#include <cstdio>
#define INF 123456789
// Floyd-Warshall
int main(){
    int n,m,dist[201][201],from[201][201];
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
        }
    }
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;
        dist[u][v] = w;
        dist[v][u] = w;
        from[u][v] = v;
        from[v][u] = u;
    }
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    from[i][j] = from[i][k];
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j){
                printf("- ");
                continue;
            }
            printf("%d ", from[i][j]+1);
        }
        printf("\n");
    }
    return 0;
}