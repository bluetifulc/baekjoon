#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 입국 심사
// Paremetric Search

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,judge[100'001];
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> judge[i];
    }
    ll lo = 0, hi = 1e18;
    while(lo <= hi){
        ll mid = (lo+hi) / 2;
        ll count = 0;
        for(int i = 0; i < n; ++i){
            count += mid / judge[i];
            if(count >= m){
                break;
            }
        }
        if(count >= m){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout << lo << "\n";

    return 0;
}