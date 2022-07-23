#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int, int>
using namespace std;
// MooTube(Silver)
// BFS


vector<P> adj[5'001];

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n-1; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }
    for(int i = 0; i < q; ++i){
        int k, v;
        scanf("%d %d", &k, &v);
        queue<P> q;
        bool visited[5'001] = { 0, };
        int cnt = 0;
        visited[v] = true;
        q.push(make_pair(1'000'000'111, v));
        while(!q.empty()){
            int cur = q.front().second;
            int weight = q.front().first;
            q.pop();
            for(P& p: adj[cur]){
                int next = p.second;
                int w = min(weight, p.first);
                if(!visited[p.second] && w >= k){
                    visited[p.second] = true;
                    ++cnt;
                    q.push(make_pair(w, p.second));
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}