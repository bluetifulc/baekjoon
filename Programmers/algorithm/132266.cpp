#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 부대복귀
// BFS

int dist[100'001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> adj;
    adj.resize(n+1);
    int m = roads.size();
    fill(dist, dist+n+1, -1);
    for(int i = 0; i < m; ++i){
        int u = roads[i][0], v = roads[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next: adj[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur]+1;
                q.push(next);
            }
        }
    }
    for(int src: sources){
        answer.push_back(dist[src]);
    }
    return answer;
}