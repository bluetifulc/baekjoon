#include <string>
#include <vector>
#include <algorithm>
// 양과 늑대
// DFS, Back-tracking

using namespace std;

vector<int> adj[21];
bool visited[21][21][21];
int answer;

void dfs(int cur, int sheep, int wolf, vector<int>& info){
    if(cur == 0){
        answer = max(answer, sheep);
    }
    for(int next: adj[cur]){
        if(info[next] == 1){
            if (!visited[next][sheep][wolf+1]&& sheep > wolf + 1) {
                visited[next][sheep][wolf+1] = true;
                info[next] = -1;
                dfs(next, sheep, wolf+1, info);
                info[next] = 1;
                visited[next][sheep][wolf+1] = false;
            }
        }else if(info[next] == 0){
            if (!visited[next][sheep+1][wolf]) {
                visited[next][sheep+1][wolf] = true;
                info[next] = -1;
                dfs(next, sheep+1, wolf, info);
                info[next] = 0;
                visited[next][sheep+1][wolf] = false;
            } 
        }else{
            if (!visited[next][sheep][wolf]) {
                visited[next][sheep][wolf] = true;
                dfs(next, sheep, wolf, info);
                visited[next][sheep][wolf] = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i = 0; i < edges.size(); ++i){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    info[0] = -1;
    visited[0][1][0] = true;
    dfs(0,1,0, info);
    return answer;
}