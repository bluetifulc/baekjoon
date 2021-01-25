#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
    int cur, dist, cost;
    point(int a,int b,int c):cur(a), dist(b), cost(c){}
    point():point(0,0,0){}
    bool operator>(const point& right) const{
        return dist > right.dist;
    }
};

struct edge{
    int end ,dist, cost;
    edge(int a,int b,int c):end(a), dist(b), cost(c){}
    edge():edge(0,0,0){}
};

int main(){
    int k,n,r;
    vector<edge> adj[101];
    scanf("%d%d%d",&k,&n,&r);
    for(int i = 0; i < r; ++i){
        int s,d,l,t;
        scanf("%d %d %d %d",&s,&d,&l,&t);
        adj[s].push_back(edge(d,l,t));
    }
    int dist[101][10'001];
    int result = 123456789;
    bool flag = false;
    bool visited[101][10'001] = { 0, };
    priority_queue<point, vector<point>, greater<point>> pq;
    memset(dist, 123456789, sizeof(dist));
    pq.push(point(1,0,0));
    dist[1][0] = 0;
    while(!pq.empty()){
        int cur,d,cost;
        do{
            cur = pq.top().cur;
            d = pq.top().dist;
            cost = pq.top().cost;
            pq.pop();
        }while(visited[cur][cost] && !pq.empty());
        if(visited[cur][cost]) break;
        if(cur == n){
            flag = true;
            if(result > dist[n][cost]){
                result = dist[n][cost];
            }
        }
        visited[cur][cost] = true;
        for(auto p: adj[cur]){
            if(cost+p.cost <= k){
                if(dist[p.end][cost+p.cost] > dist[cur][cost] + p.dist){
                    dist[p.end][cost+p.cost] = dist[cur][cost] + p.dist;
                    pq.push(point(p.end, dist[p.end][cost+p.cost], cost+p.cost));
                }
            }
        }
    }
    if(flag) printf("%d\n",result);
    else printf("-1\n");
    return 0;
}