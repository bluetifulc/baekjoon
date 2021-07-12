#include <cstdio>
#include <vector>
// 비밀 모임
// Floyd-Warshall
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        int dist[101][101];
        scanf("%d %d",&n, &m);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dist[i][j] = 123456789;
            }
        }
        for(int i = 0; i < m; ++i){
            int u,v,w;
            scanf("%d %d %d", &u, &v, &w);
            dist[u][v] = w;
            dist[v][u] = w;
        }
        int k;
        scanf("%d",&k);
        vector<int> f;
        for(int i = 0; i < k; ++i){
            int u;
            scanf("%d",&u);
            f.push_back(u);
        }
        for(int k = 1; k <= n; ++k){
              for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    if(dist[i][j] > dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int room = 0, mini = 123456789;
        for(int i = 1; i <= n; ++i){
            int sum = 0;
            for(int fri: f){
                if(fri == i) continue;
                sum += dist[fri][i];
            }
            if(sum < mini){
                mini = sum;
                room = i;
            }
        }
        printf("%d\n", room);
    }
    return 0;
}