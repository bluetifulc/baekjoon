#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 200'001
using namespace std;
// BFS + GRAPH(indegree)

int main(){
    int n;
    int indegree[MAX] = { 0, };
    int totalIndegree[MAX] = { 0, };
    vector<int> adj[MAX];

    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        int t;
        scanf("%d",&t);
        while(t != 0){
            if(t > i){
                adj[i].push_back(t);
                adj[t].push_back(i);
                totalIndegree[i]++;
                totalIndegree[t]++;
            }
            scanf("%d",&t);
        }
    }
    int m, dist[MAX] = { 0, };
    bool visited[MAX] = { 0, };
    queue<int> q;
    fill(dist,dist+n+1,-1);
    scanf("%d",&m);
    for(int i = 0; i < m; ++i){
        int t;
        scanf("%d",&t);
        q.push(t);
        visited[t] = true;
        dist[t] = 0;
    }
    int time = 1;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            int cur = q.front();
            q.pop();
            for(int next: adj[cur]){
                if(!visited[next]){
                    indegree[next]++;
                    if(indegree[next]*2 >= totalIndegree[next]){
                        dist[next] = time;
                        q.push(next);
                        visited[next] = true;
                    }
                } 
            }
        }
        time++;
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ",dist[i]);
    }
    printf("\n");
    return 0;
}