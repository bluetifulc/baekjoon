#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#define P pair<int,int>
// 길 찾기 게임
// Tree
using namespace std;
struct node{
    int y,x,idx;
    node(int y,int x,int idx)
    :y(y), x(x), idx(idx){};
    bool operator<(const node& right) const{
        if(y != right.y) return y < right.y;
        return x > right.x;
    }
};
vector<int> pre;
vector<int> post;
int left[10'001];
int right[10'001];
int y[10'001],x[10'001];
void insert(int par,int cur, int curx){
    while(true){
        if(curx > x[par]){
            if(right[par] == 0){
                right[par] = cur;
                return;
            }
            par = right[par];
        }else{
            if(left[par] == 0){
                left[par] = cur;
                return;
            }
            par = left[par];
        }
    }
}
void prefind(int idx){
    pre.push_back(idx);
    if(left[idx] != 0) prefind(left[idx]);
    if(right[idx] != 0) prefind(right[idx]);
}
void postfind(int idx){
    if(left[idx] != 0) postfind(left[idx]);
    if(right[idx] != 0) postfind(right[idx]);
    post.push_back(idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {  
    vector<vector<int>> answer;
    priority_queue<node> pq;
    for(int i = 0; i < nodeinfo.size(); ++i){
        pq.push(node(nodeinfo[i][1], nodeinfo[i][0], i+1));
        y[i+1] = nodeinfo[i][1];
        x[i+1] = nodeinfo[i][0];
    }
    int rootidx = pq.top().idx;
    pq.pop();
    while(!pq.empty()){
        insert(rootidx, pq.top().idx ,pq.top().x);
        pq.pop();
    }
    prefind(rootidx);
    postfind(rootidx);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}

int main(){
    vector<vector<int>> input = {
        {5,3}, {11,5}, {13,3}, {3,5},
        {6,1}, {1,3}, {8,6}, {7,2}, {2,2}
    };
    vector<vector<int>> answer = solution(input);
    for(int i = 0; i < answer[0].size(); ++i)
        printf("%d ", answer[0][i]);
    printf("\n");
    for(int i = 0; i < answer[1].size(); ++i)
        printf("%d ", answer[1][i]);
    printf("\n");
    return 0;
}