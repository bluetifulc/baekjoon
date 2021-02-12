#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 123456789;
// Floyd-Warshall

int main(){
    int n,m,dist[101][101];
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
        }
    }
    for(int i = 0; i < m; ++i){
        int u,v;
        scanf("%d %d",&u,&v);
        dist[u][v] = 1;
        dist[v][u] = 1; 
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][j] > dist[i][k]+dist[k][j]) dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    std::vector<int> result;
    bool visited[101] = { 0 ,}; 
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            std::vector<int> temp;
            temp.push_back(i);
            visited[i] = true;
            for(int j = i+1; j <= n; ++j){
                if(!visited[j] && dist[i][j]!=123456789){
                    temp.push_back(j);
                    visited[j] = true;
                }
            }
            int idx = 0, mini=123456789;
            for(int i = 0; i < temp.size(); ++i){
                int tempMaxi = 0;
                for(int j = 0; j < temp.size(); ++j){
                    if(i == j) continue;
                    if(dist[temp[i]][temp[j]] > tempMaxi){
                        tempMaxi = dist[temp[i]][temp[j]];
                    }
                }
                if(tempMaxi < mini){
                    idx = temp[i];
                    mini = tempMaxi;
                }
            }
            result.push_back(idx);
        }
    }
    printf("%zu\n", result.size());
    std::sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); ++i){
        printf("%d\n",result[i]);
    }
    return 0;
}