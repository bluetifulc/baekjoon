#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 아우으 우아으이야!!
// Sweeping

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int result = 0, last = -1234567890;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        if(y < last){
            continue;
        }
        if(x > last){
            result += y-x;
        }else{
            result += y - last;
        }
        last = y;

    }
    cout << result << endl;

    return 0;
}