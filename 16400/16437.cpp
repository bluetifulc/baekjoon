#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 양 구출 작전
// dfs

int n;
ll counts[123'460];
vector<int> adj[123'460];

ll dfs(int idx){
    ll& ref = counts[idx];
    for(int next: adj[idx]){
        ref += dfs(next);
    }
    if(ref < 0){
        ref = 0;
    }
    return ref;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 2; i <= n; ++i){
        char a;
        int p;
        cin >> a >> counts[i] >> p;
        if(a == 'W'){
            counts[i] *= -1;
        }
        adj[p].push_back(i);
    }
    cout << dfs(1) << "\n";
    return 0;
}