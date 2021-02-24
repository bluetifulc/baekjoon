#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 123456789000
#define ll long long
using namespace std;
// Daijkstra

struct wolf{
    ll w;
    int cur,status;
    wolf(ll a, int b,int c):w(a),cur(b),status(c){}
};
bool operator>(const wolf& left, const wolf& right){
    return left.w > right.w;
}
int main(){
    int n,m;
    vector<pair<ll,int>> adj[4'001];
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }
    priority_queue<wolf, vector<wolf>, greater<wolf> > wolfq;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int> > > foxq;
    bool wolfvisited[4'001][2] = {0,};
    bool foxvisited[4'001] = {0,};
    ll wolfdist[4'001][2],foxdist[4'001];
    fill(foxdist, foxdist+n+1, INF);
    for(int i = 0; i <= n; ++i){
        wolfdist[i][0] = INF;
        wolfdist[i][1] = INF;
    }
    wolfq.push(wolf(0,1,0));
    foxq.push(make_pair(0,1));
    wolfdist[1][0] = 0;
    foxdist[1] = 0;
    while(!foxq.empty()){
        int cur;
        ll w;
        do{
            w = foxq.top().first;
            cur = foxq.top().second;
            foxq.pop();
        }while(!foxq.empty() && foxvisited[cur]);
        if(foxvisited[cur]) break;
        foxvisited[cur] = true;
        for(auto& p: adj[cur]){
            int next = p.second;
            ll d = p.first*2;
            if(!foxvisited[next] && w+d < foxdist[next]){
                foxdist[next] = w+d;
                foxq.push(make_pair(foxdist[next], next));
            }
        }
    }
    
    while(!wolfq.empty()){
        int cur,status;
        ll w;
        do{
            w = wolfq.top().w;
            cur = wolfq.top().cur;
            status=wolfq.top().status;
            wolfq.pop();
        }while(!wolfq.empty() && wolfvisited[cur][status]);
        if(wolfvisited[cur][status]) break;
        wolfvisited[cur][status] = true;
        for(auto& p: adj[cur]){
            int next = p.second;
            ll d = p.first;
            if(status == 1) d *= 4;
            if(!wolfvisited[next][1-status] && w+d < wolfdist[next][1-status]){
                wolfdist[next][1-status] = w+d;
                wolfq.push(wolf(wolfdist[next][1-status], next, 1-status));
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= n; ++i){
        if(wolfdist[i][0] > foxdist[i] && wolfdist[i][1] > foxdist[i]) ++result;
    }
    printf("%d\n", result);
    return 0;
}