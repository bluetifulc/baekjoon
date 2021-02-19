#include <cstdio>
#include <queue>
using namespace std;
// Brute-Force Graph
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> oil;
    priority_queue<int> canGo;
    for(int i = 1; i <= n; ++i){
        int a,b;
        scanf("%d%d",&a,&b);
        oil.push(make_pair(a,b));
    }
    int dest,result = 0, leftOil = 0;
    scanf("%d%d",&dest,&leftOil);
    while(leftOil < dest){
        while(!oil.empty() && leftOil >= oil.top().first){
            canGo.push(oil.top().second);
            oil.pop();
        }
        if(canGo.empty()){
            result = -1;
            break;
        }
        leftOil += canGo.top();
        canGo.pop();
        result++;
    }
    printf("%d\n",result);
    return 0;
}
