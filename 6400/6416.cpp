#include <cstdio>
#include <set>
#include <vector>
#include <queue>
// 트리인가 ?
// Tree
using namespace std;
vector<int> adj[100'001];
bool visited[100'001];
int main(){
    int a,b, test = 1, count = 0;
    int indegree[100'001];
    set<int> nodes;
    queue<int> q;

    while(true){
        scanf("%d%d",&a,&b);
        if(a < 0 && b < 0) break;
        if(a == 0 && b == 0){ // Tree validation
            bool flag = true;
            int root = -1;
            for(int i: nodes){
                if(indegree[i] >= 2) flag = false;
                else if(indegree[i] == 0) root = i;
            }
            q.push(root);
            visited[root] = true;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int next: adj[cur]){
                    if(!visited[next]){
                        q.push(next);
                        visited[next] = true;
                    }else{
                        flag = false;
                    }
                }
            }
            for(int i: nodes){
                if(!visited[i]) flag = false;
            }

            if(flag){
                printf("Case %d is a tree.\n", test);
            }else{
                printf("Case %d is not a tree.\n", test);
            }
            // initialize
            test++;
            count = 0;
            nodes.clear();
            for(int i = 0; i < 100'001; ++i){
                indegree[i] = 0;
                visited[i] = false;
                adj[i].clear();
            }
        }else{
            count++;
            nodes.insert(a);
            nodes.insert(b);
            adj[a].push_back(b);
            indegree[b]++;
        }
    }
    return 0;
}   