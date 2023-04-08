#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 연속된 부분 수열의 합
// two-pointer

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size(), maxi = 123456789;
    int cur = sequence[0], lo = 0, hi = 0;
    while(true){
        if(cur == k && hi - lo < maxi){
            answer.clear();
            answer.push_back(lo);
            answer.push_back(hi);
            maxi = hi - lo;
        }
        if(cur > k && lo < hi){
            cur -= sequence[lo];
            ++lo;
        }else{
            ++hi;
            cur += sequence[hi];
        }
        if(lo >= n || hi >= n){
            break;
        }
    }

    return answer;
}

int main(){
    vector<int> seq = {1,2,3,4,5};
    vector<int> a = solution(seq, 7);
    cout << a[0] << " " << a[1] << endl;

    return 0;   
}