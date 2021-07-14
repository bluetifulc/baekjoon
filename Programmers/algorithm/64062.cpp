#include <iostream>
#include <string>
#include <vector>
// 징검다리 건너기
// Binary Search
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    unsigned int lo = 1, hi = 200'000'001;
    while(lo < hi){
        unsigned int mid = (lo+hi)/2;
        int st = 0;
        for(int i = 0; i < stones.size(); ++i){
            if(stones[i] > mid){
                st = 0;
                continue;
            }
            if(++st >= k){
                break;
            }
        }

        if(st >= k){
            answer = mid;
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    return answer;
}

int main(){
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    std::cout << solution(stones, k) << "\n";
    return 0;
}