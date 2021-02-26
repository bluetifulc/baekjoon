#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
// Sweeping
pair<int,int> pairs[1'000'001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        pairs[i] = make_pair(u,v);
    }
    sort(pairs,pairs+n);
    int result = 0, left = -1234567890, right = -1234567890;
    for(int i = 0; i < n; ++i){
        if(right < pairs[i].first){
            result += right-left;
            left = pairs[i].first;
            right = pairs[i].second;
        }
        else{
            right = max(right, pairs[i].second);
        }
    }
    result += right-left;
    printf("%d\n",result);
    return 0;
}