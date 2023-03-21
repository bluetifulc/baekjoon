#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 시소 짝꿍
// Map

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> m;
    sort(weights.begin(), weights.end());
    for(int cur: weights){
        if(m.find(cur) != m.end()){
            answer += m[cur];
        }
        if(cur % 3 == 0 && m.find(cur/3*2) != m.end()){
            answer += m[cur/3*2];
        }
        if(cur % 2 == 0 && m.find(cur/2) != m.end()){
            answer += m[cur/2];
        }
        if(cur % 4 == 0 && m.find(cur/4*3) != m.end()){
            answer += m[cur/4*3];
        }
        m[cur]++;
    }
    return answer;
}