#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
// 베스트앨범
// Hash, Priority-Queue
using namespace std;

struct cmp{
    bool operator()(const pair<int,int>& left, const pair<int,int>& right) const{
        if(left.first != right.first) return left.first < right.first;
        return left.second > right.second;
    }
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq[101];
    vector<int> cd[101];
    map<string, int> hash;
    int sum[101] = { 0,};
    int idx = 0;
    for(int i = 0; i < genres.size(); ++i){
        if(hash.find(genres[i]) == hash.end()){
            hash.insert({genres[i], idx++});
        }
        sum[hash[genres[i]]] += plays[i];
        pq[hash[genres[i]]].push(make_pair(plays[i],i));
    }
    priority_queue<pair<int,int>> gpq;
    for(int i = 0; i < idx; ++i){
        gpq.push(make_pair(sum[i], i));
    }
    while(!gpq.empty()){
        int cur = gpq.top().second;
        gpq.pop();
        answer.push_back(pq[cur].top().second);
        pq[cur].pop();
        if(!pq[cur].empty()){
            answer.push_back(pq[cur].top().second);
        }
    }
    return answer;
}