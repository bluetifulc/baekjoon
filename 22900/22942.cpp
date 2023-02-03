#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
// 데이터체커
// Stack

struct coord{
    int x, o, idx;
};

bool cmp(coord& a, coord& b){
    return a.x < b.x;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    vector<coord> vec;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x, r;
        cin >> x >> r;
        vec.push_back({x-r, 0, i});
        vec.push_back({x+r, 1, i});
    }
    sort(vec.begin(), vec.end(), cmp);

    stack<int> st;
    st.push(vec[0].idx);
    for(int i = 1; i < vec.size(); ++i){
        if(vec[i].x == vec[i-1].x){
            cout << "NO\n";
            return 0;
        }
        if(vec[i].o == 0){
            st.push(vec[i].idx);
        }else if(st.top() == vec[i].idx){
            st.pop();
        }else{
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}