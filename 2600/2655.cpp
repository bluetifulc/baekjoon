#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
// DP (Dynamic Programming) + Back-Tracking
struct brick{
    int area,height,weight,idx;
    brick(int a,int b,int c,int d):area(a),height(b),weight(c),idx(d){}
    bool operator>(const brick& right){
        if(area != right.area) return area>right.area;
        return weight > right.weight;
    }
};
bool cmp(const brick& left, const brick& right){
    if(left.area != right.area) return left.area > right.area;
    return left.weight > right.weight;
}
int n,dp[101][10'002];
vector<brick> bricks;
int solve(int idx, int weight){
    if(idx == n) return 0;
    int &ref = dp[idx][weight];
    if(ref != 0) return ref;
    for(int i = idx; i <= n; ++i){
        if(weight >= bricks[i].weight){
            ref = max(ref, bricks[i].height + solve(i+1, bricks[i].weight));
        }
    }
    return ref;
}

vector<int> result;
void track(int idx, int weight){
    for(int i = idx; i < n; ++i){
        if(dp[idx][weight] == bricks[i].height + dp[i+1][bricks[i].weight]){
            result.push_back(bricks[i].idx);
            track(i+1,bricks[i].weight);
            break;
        }
    }  
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        bricks.push_back(brick(a,b,c,i+1));
    }
    sort(bricks.begin(),bricks.end(),cmp);
    solve(0,10001);
    track(0,10001);
    printf("%zu\n",result.size());
    for(int i = result.size()-1; i >= 0; --i){
        printf("%d\n", result[i]);
    }
    return 0;
}
