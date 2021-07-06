#include <iostream>
#include <vector>
#include <queue>
// 나무 위의 빗물
// BFS, Graph
using namespace std;

vector<int> adj[500'001];
bool visited[500'001];
int main(){
    int n,w,leaves=0;
    scanf("%d %d",&n,&w);
    for(int i = 0; i < n-1; ++i){
        int u,v;
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front();
        bool leaf = true;
        q.pop();
        for(int next: adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                leaf = false;
            }
        }
        if(leaf) leaves++;
    }
    cout.precision(6);
    cout << fixed << (double)w/leaves << endl;
    return 0;
}