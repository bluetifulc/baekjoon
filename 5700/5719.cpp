#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define P pair<int,int>
// 거의 최단 경로
// Dijkstra, TraceBack
using namespace std;

const int INF = 123456789;
int n,m,s,d;
vector<P> adj[501];
vector<int> path[501];
int cost[501];
bool visited[501] = { 0, };

void dijkstra(){
    for(int i = 0; i < n; ++i){
        path[i].clear();
        cost[i] = INF;
        visited[i] = false;
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int w = pq.top().first, cur = pq.top().second;
        pq.pop();
        while(visited[cur] && !pq.empty()){
            w = pq.top().first, cur = pq.top().second;
            pq.pop();
        }
        if(visited[cur]) break;
        visited[cur] = true;

        for(P &coord: adj[cur]){
            int next = coord.second, dw = coord.first;
            if(!visited[next] && w + dw < cost[next]){
                cost[next] = w+dw;
                path[next].clear();
                pq.push(make_pair(cost[next], next));
            }
            if(w + dw == cost[next]){
                path[next].push_back(cur);
            }
        }
    }
}

void removeShort(int u){
    if(u == s) return;
    for(int v: path[u]){
        vector<P>::iterator iter = adj[v].begin();
        for(; iter != adj[v].end(); ++iter){
            if((*iter).second == u){
                adj[v].erase(iter);
                removeShort(v);
                break;
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    while(n != 0 && m != 0){
        for(int i = 0; i < n; ++i){
            adj[i].clear();
        }
        scanf("%d %d",&s,&d);
        for(int i = 0; i < m; ++i){
            int u,v,p;
            scanf("%d %d %d",&u,&v,&p);
            adj[u].push_back(make_pair(p,v));
        }
        dijkstra();

        removeShort(d);

        dijkstra();
        printf("%d\n", cost[d] == INF ? -1 : cost[d]);

        scanf("%d %d",&n, &m);
    }
    return 0;
}