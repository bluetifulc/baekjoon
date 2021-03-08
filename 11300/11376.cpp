#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 2004
using namespace std;
// Bipartite Matching
int n,m,A[MAX], B[MAX];
bool visited[MAX];
vector<int> adj[MAX];
int dfs(int a){
    visited[a] = true;
    for(int b: adj[a]){
        if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        int t;
        scanf("%d",&t);
        while(t--){
            int u;
            scanf("%d",&u);
            adj[i].push_back(u-1);
            adj[1001+i].push_back(u-1);
        }
    }
    int result = 0;
    fill(A,A+MAX, -1);
    fill(B,B+MAX, -1);
    for(int i = 0; i < n; ++i){
        if(A[i] == -1){
            fill(visited,visited+MAX, false);
            if(dfs(i)) result++;
        }
    }
    for(int i = 1001; i < n+1001; ++i){
        if(A[i] == -1){
            fill(visited,visited+MAX, false);
            if(dfs(i)) result++;
        }
    }
    printf("%d\n", result);
    return 0;
}