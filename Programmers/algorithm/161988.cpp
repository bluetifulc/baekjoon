#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 연속 펄스 부분 수열의 합
// DP

ll cache[500'001];

long long solution(vector<int> sequence) {
    long long answer = 0;
    int n = sequence.size();
    for(int i = 0; i < n; i+=2){
        sequence[i] *= -1;
    }

    cache[0] = sequence[0];
    answer = max(answer, cache[0]);
    for(int i = 1; i < n; ++i){
        cache[i] = max(0ll, cache[i-1]) + sequence[i];
        answer = max(answer, cache[i]);
    }

    fill(cache, cache+n, 0);
    for(int i = 0; i < n; ++i){
        sequence[i] *= -1;
    }

    cache[0] = sequence[0];
    answer = max(answer, cache[0]);
    for(int i = 1; i < n; ++i){
        cache[i] = max(0ll, cache[i-1]) + sequence[i];
        answer = max(answer, cache[i]);
    }

    return answer;
}
