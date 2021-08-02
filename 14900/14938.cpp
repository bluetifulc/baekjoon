#include <cstdio>
#include <cstring>
// 서강그라운드
// Floyd-Warshall
int main(){
    int n,m,r;
    int reward[101];
    int dist[101][101];
    scanf("%d %d %d",&n,&m,&r);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &reward[i]);
        memset(dist[i], 123456789, sizeof(dist[i]));
    }
    for(int i = 0; i < r; ++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= n; ++i){
        int sum = reward[i];
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            if(dist[i][j] <= m){
                sum += reward[j];
            }
        }
        if(sum > result) result = sum;
    }
    printf("%d\n", result);
    return 0;
}