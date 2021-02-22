#include <cstdio>
#include <queue>
using namespace std;
// Greedy + Queue
int main(){
    int n;
    priority_queue<pair<int,int>> lecture;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int p,d;
        scanf("%d%d",&p, &d);
        lecture.push(make_pair(p,d));
    }
    int result = 0;
    bool checked[10'001] = { 0, };
    while(!lecture.empty()){
        for(int i = lecture.top().second; i >= 1; --i){
            if(!checked[i]){
                checked[i] = true;
                result += lecture.top().first;
                break;
            }
        }
        lecture.pop();
    }
    printf("%d\n", result);
    return 0;
}