#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
// 보석 쇼핑
// Two Pointer
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> kind;
    unordered_map<string, int> gem;
    for(int i = 0; i < gems.size(); ++i){
        kind.insert(gems[i]);
    }
    int loidx = 0, hiidx = 0, maxi = 1234567890;
    int cnt = 0, dest = kind.size();
    int lo = 0, hi = 0;
    gem[gems[0]]++;
    while(lo <= hi){
        if(hi-lo+1 >= maxi){
            gem[gems[lo]]--;
            if(gem[gems[lo]] == 0){
                gem.erase(gems[lo]);
            }
            lo++;
            continue;
        }
        cnt = gem.size();
        if(cnt == dest){
            if(hi-lo+1 < maxi){
                maxi = hi-lo+1;
                loidx = lo;
                hiidx = hi;
            }
            gem[gems[lo]]--;
            if(gem[gems[lo]] == 0){
                gem.erase(gems[lo]);
            }
            lo++;
        }else{
            hi++;
            if(hi == gems.size()) break;
            gem[gems[hi]]++;
        }
    }
    answer.push_back(loidx+1);
    answer.push_back(hiidx+1);
    return answer;
}