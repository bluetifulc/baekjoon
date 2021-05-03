#include <cstdio>
#include <queue>
#include <vector>
#define p pair<int,int>
using namespace std;
// 12764 싸지방에 간 준하
// Prioirty-Queue
inline int max(int a, int b){ return a > b ? a : b; }
int pc[100'002];
int cnt, answer[100'002];
int main(){
    priority_queue<p, vector<p>, greater<p>> pq;
    priority_queue<int, vector<int>, greater<int>> emptypc;
    priority_queue<p, vector<p>, greater<p>> usingpc;
    int n,u,v;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d",&u,&v);
        emptypc.push(i);
        pq.push(make_pair(u,v));
    }
    while(!pq.empty()){
        while(!usingpc.empty() && pq.top().first > usingpc.top().first){
            emptypc.push(usingpc.top().second);
            usingpc.pop();
        }
        cnt = max(cnt, emptypc.top()+1);
        answer[emptypc.top()]++;
        usingpc.push(make_pair(pq.top().second, emptypc.top()));
        emptypc.pop();
        pq.pop();
    }
    printf("%d\n", cnt);
    printf("%d ", answer[0]);
    for(int j = 1; j < cnt; ++j){
        printf("%d ", answer[j]);
    }
    printf("\n");
    return 0;
}