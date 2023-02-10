#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
// 현수의 열기구 교실
// Bit-masking

int main(){
    int n;
    while(cin >> n){
        set<int> s;
        for(int i = 0; i < n; ++i){
            int t, bit = 0;
            cin >> t;
            while(t){
                int c = (t % 10) - 1;
                bit |= (1 << c);
                t /= 10;
            }
            s.insert(bit);
        }
        cout << s.size() << "\n";
    }
    return 0;
}