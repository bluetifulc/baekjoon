#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 인사고과
// Sort

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int me0 = scores[0][0], me1 = scores[0][1];
    sort(scores.begin(), scores.end(), [](vector<int>& lo, vector<int>& hi){
        return lo[0] == hi[0] ? lo[1] < hi[1] : lo[0] > hi[0];
    });

    int maxi = 0;
    for(int i = 0; i < scores.size(); ++i){
        if(scores[i][1] < maxi){
            if(scores[i][0] == me0 && scores[i][1] == me1){
                return -1;
            }
        }else{
            maxi = max(maxi, scores[i][1]);
            if(scores[i][0] + scores[i][1] > me0+me1){
                ++answer;
            }
        }
    }
    
    return answer;
}