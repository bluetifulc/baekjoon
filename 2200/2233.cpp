#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[2002];
int parent[2002][11];
int depth[2002];
int where[4004];
int main(){
    int n,cnt = 0;
    stack<int> s;
    scanf("%d",&n);

    memset(parent,-1,sizeof(parent));
    fill(depth,depth+n,-1);
    s.push(0);
    for(int i = 1; i <= 2*n; ++i){
        int t;
        scanf("%1d",&t);
        if(t == 0){
            cnt++;
            parent[cnt][0] = s.top();
            depth[cnt] = s.size()-1;
            s.push(cnt);
            where[i] = s.top();
        }else{
            where[i] = s.top();
            s.pop();
        }
    }
    parent[1][0] = -1;
    for(int j = 0; j < 10; ++j){
        for(int i = 1; i <= n; ++i){
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];
        }
    }
    int u,v;
    scanf("%d%d", &u,&v);
    u = where[u];
    v = where[v];
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u]-depth[v];
    for(int j = 0; diff; ++j){
        if(diff % 2) u = parent[u][j];
        diff /= 2;
    }
    if(u != v){
        for(int j = 10; j >= 0; --j){
            if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                u = parent[u][j];
                v = parent[v][j];
            }
        }
        u = parent[u][0];
    }
    bool flag = false;
    for(int i = 1; i <= 2*n; ++i){
        if(where[i] == u) {
            if(!flag){ 
                printf("%d ", i);
                flag = true;
            }
            else{
                printf("%d\n", i);
            }
        }
    }
    // printf("\n");
    return 0;
}