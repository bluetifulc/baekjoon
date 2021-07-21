#include <cstdio>
#include <vector>
// 플로이드 2
// Floyd-Warshall
using namespace std;
int route[101][101];
vector<int> curr;
void search(int start, int end){
    if(route[start][end] == 0){
        curr.push_back(start);
        curr.push_back(end);
        return;
    }
    search(start, route[start][end]);
    curr.pop_back();
    search(route[start][end], end);
}
int main(){
    int n,m;
    int dist[101][101];
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dist[i][j] = 123456789;
            if(i == j) dist[i][j] = 0;
        }
    }
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        if(w < dist[u][v]) dist[u][v] = w;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j] = k;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(dist[i][j] == 123456789) printf("0 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j || dist[i][j] == 123456789){
                printf("0 ");
            }else{
                curr.clear();
                search(i,j);
                printf("%d ", curr.size());
                for(int e: curr){
                    printf("%d ", e);
                }
            }
            printf("\n");
        }
    }
    return 0;
}