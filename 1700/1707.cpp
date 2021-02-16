#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
// BFS
int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        int v,e,color[20'001] = { 0, };
        vector<int> adj[20'001];
        scanf("%d%d",&v,&e);
        for(int i = 0; i < e; ++i){
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = true;
        for(int i = 1; i <= v; ++i){
            if(color[i] != 0) continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int cur = q.front();
                int nextColor = 3 - color[cur];
                q.pop();
                for(int next: adj[cur]){
                    if(color[next] == 0){
                        color[next] = nextColor;
                        q.push(next);
                    }else if(color[next] == color[cur]){
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}