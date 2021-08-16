#include <cstdio>
#include <vector>
#include <algorithm>
// 택배
// Greedy
using namespace std;

struct coord{
    int from,to,box;
    coord(int from, int to, int box)
        :from(from), to(to), box(box){}
};
bool cmp(const coord& a, const coord& b){
    return a.to < b.to;
}

int n,c,m;
int main(){
    int left[2'001], result = 0;
    vector<coord> input;
    scanf("%d %d %d", &n,&c, &m);
    for(int i = 0; i < m; ++i){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        input.push_back(coord(u,v,w));
    }
    fill(left, left+n, c);
    sort(input.begin(), input.end(), cmp);
    for(int i = 0; i < m; ++i){
        int mini = left[input[i].from];
        for(int j = input[i].from+1; j < input[i].to; ++j){
            mini = min(mini, left[j]);
        }
        if(mini > input[i].box) mini = input[i].box; 
        for(int j = input[i].from; j < input[i].to; ++j){
            left[j] -= mini;
        }
        result += mini;
    }
    printf("%d\n", result);
    return 0;
}