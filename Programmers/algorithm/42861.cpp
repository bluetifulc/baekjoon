#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 섬 연결하기
// Union-Find
int p[102];
int find(int a){
    if(p[a] == -1) return a;
    return p[a] = find(p[a]);
}
bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    p[b] = a;
    return true;
}
bool compare(const vector<int> &left, const vector<int> &right){
    return left[2]<right[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0, cnt = 1;
    for(int i = 0; i < n; ++i) p[i] = -1;
    sort(costs.begin(), costs.end(), compare);
    for(int i = 0; i < costs.size(); ++i){
        if(cnt == n) break;
        if(merge(costs[i][0], costs[i][1])){
            answer += costs[i][2];
            cnt++;
        }
    }
    return answer;
}