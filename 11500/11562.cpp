#include <cstdio>
#include <algorithm>
// Graph, Shortest Path ( Floyd-Warshall )
int main(){
    int n,m,dist[251][251];
    scanf("%d%d",&n,&m);
    std::fill(&dist[0][0], &dist[250][251], 123456789);
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w == 0){
            dist[u][v] = 0;
            dist[v][u] = 1;
        }else{
            dist[u][v] = 0;
            dist[v][u] = 0;
        }
    }
    for(int i = 1; i <= n; ++i){
        dist[i][i] = 0;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

    int k;
    scanf("%d",&k);
    for(int i = 0; i < k; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n", dist[u][v]);
    }
}