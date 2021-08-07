#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
// 등산
// Dijkstra
using namespace std;

const ll INF = (ll)1987654321987654321;
int n,m,d,e;
int height[100'001];
vector<pair<int,int>> adj[100'001];
ll dist[100'001][2];
void daijkstra(int start){
    bool visited[100'001] = { 0, };
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    if(start == 0){
        pq.push(make_pair(0,1));
        dist[1][0] = 0;
    }else{
        pq.push(make_pair(0,n));
        dist[n][1] = 0;
    }
    while(!pq.empty()){
        int cur;
        ll d;
        do{
            cur = pq.top().second;
            d = pq.top().first;
            pq.pop();
        }while(!pq.empty() && visited[cur]);
        if(visited[cur]) break;
        visited[cur] = true;
        for(pair<int,int>& p: adj[cur]){
            int next = p.second;
            ll w = p.first;
            if(!visited[next] && height[next] > height[cur] && dist[next][start] > (ll)d+(ll)w){
                dist[next][start] = (ll)d+(ll)w;
                pq.push(make_pair(dist[next][start], next));
            }
        }
    }
}

int main(){
    scanf("%d %d %d %d",&n,&m,&d,&e);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&height[i]);
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }
    daijkstra(0);
    daijkstra(1);
    ll result = -INF;
    for(int i = 2; i < n; ++i){
        if(height[i] != 1){
            if(dist[i][0] == INF || dist[i][1] == INF) continue;
            ll sum = (ll)height[i] * e - (dist[i][0] + dist[i][1])*d;
            if(sum > result) result = sum;
        }
    }
    if(result != -INF) printf("%lld\n", result);
    else printf("Impossible\n");

    return 0;
}