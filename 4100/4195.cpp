#include <iostream>
#include <string>
#include <map>
// 친구 네트워크
// Hash, disjoint-set
using namespace std;

int p[200'001], c[200'001];
int find(int a){
    if(p[a] == -1) return a;
    return p[a] = find(p[a]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[b] = a;
    c[a] += c[b];
}
int count(int a){
    return c[find(a)];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 200'000; ++i){
            c[i] = 1;
            p[i] = -1;
        }
        int f, idx = 0;
        string u,v;
        map<string, int> fri;
        cin >> f;
        for(int j = 0; j < f; ++j){
            cin >> u >> v;
            if(fri.find(u) == fri.end()){
                fri.insert({u,idx++});
            }
            if(fri.find(v) == fri.end()){
                fri.insert({v,idx++});
            }
            merge(fri[u], fri[v]);
            cout << count(fri[u]) << "\n";
        }
    }
    return 0;
}