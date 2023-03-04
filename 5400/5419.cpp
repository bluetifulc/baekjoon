#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 북서풍
// SegmentTree, Sweeping, 좌표압축

int tree[75001*4];
int convert[75001];
P input[75001];

int sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int idx){
    if(idx < start || idx > end) return;
    tree[node]++;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(node*2, start, mid, idx);
    update(node*2+1, mid+1, end, idx);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fill(tree, tree + 75001*4, 0);
        for(int i = 0; i < n; ++i){
            cin >> input[i].first >> input[i].second;
        }
        sort(input, input+n, [](P& lo, P& hi){return lo.second < hi.second;});

        convert[0] = 0;
        int idx = 0;
        for(int i = 1; i < n; ++i){
            if(input[i].second != input[i-1].second) ++idx;
            convert[i] = idx;
        }
        for(int i = 0; i < n; ++i){
            input[i].second = convert[i];
        }

        sort(input, input+n, [](P& lo, P& hi){
            if(lo.first == hi.first) return lo.second > hi.second;
            return lo.first < hi.first;
        });
        ll result = 0;
        for(int i = 0; i < n; ++i){
            result += sum(1, 0, 75000, input[i].second, 75000);
            update(1, 0, 75000, input[i].second);
        }
        cout << result << endl;
    }

    return 0;
}