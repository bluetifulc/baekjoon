#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
// Bipartite Matching
int n,m,k,A[2'001],B[1'001];
bool visited[2'001];
vector<int> adj[2'001];
bool dfs(int a){
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
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; ++i){
        int t;
        scanf("%d",&t);
        while(t--){
            int u;
            scanf("%d",&u);
            adj[i].push_back(u-1);
            adj[i+1000].push_back(u-1);
        }
    }
    int result = 0,countK = 0;
    fill(A,A+2001,-1);
    fill(B,B+1001,-1);
    for(int i = 0; i < n; ++i){
        if(A[i] == -1){
            fill(visited, visited+2001,false);
            if(dfs(i)) result++;
        }
    }
    for(int i = 1000; i < 1000+n; ++i){
        if(A[i] == -1){
            fill(visited, visited+2001,false);
            if(dfs(i)){ 
                result++;
                if(++countK == k) break;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}