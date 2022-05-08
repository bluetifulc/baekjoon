#include <iostream>
// 3584 가장 가까운 공통 조상
// LCA

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        int par[10'001] = { 0, };
        cin >> n;
        for(int i = 0; i < n-1; ++i){
            int u,v;
            cin >> u >> v;
            par[v] = u;
        }

        bool visited[10'001] = { false, };
        int a,b,cur;
        cin >> a >> b;
        cur = a;
        visited[a] = true;
        while(true){
            if(par[cur] == 0)
                break;
            cur = par[cur];
            visited[cur] = true;
        }

        cur = b;
        while(true){
            if(visited[cur]){
                cout << cur << endl;
                break;
            }
            cur = par[cur];
        }
    }

    return 0;
}