#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
// 트리의 부모 찾기
// BFS
vector<int> adj[100'001];
int par[100'001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n-1; ++i){
        int u,v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    par[1] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next: adj[cur]){
            if(par[next] == 0){
                par[next] = cur;
                q.push(next);
            }
        }
    }
    for(int i = 2; i <= n; ++i){
        printf("%d\n", par[i]);
    }
    return 0;
}