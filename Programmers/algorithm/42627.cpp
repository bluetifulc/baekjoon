#include <string>
#include <vector>
#include <queue>
#define P pair<int,int>
using namespace std;

int solution(vector<vector<int>> jobs) {
    priority_queue<P, vector<P>, greater<P>> jobsq;
    priority_queue<P, vector<P>, greater<P>> q;
    for(int i = 0; i < jobs.size(); ++i) jobsq.push(make_pair(jobs[i][0], jobs[i][1]));
    int time = 0, answer = 0, i = 0;
    while(!q.empty() || !jobsq.empty()){
        while(!jobsq.empty() && time >= jobsq.top().first){
            q.push(make_pair(jobsq.top().second, jobsq.top().first));
            jobsq.pop();
        }
        if(q.empty()){
            time = jobsq.top().first;
            continue;
        }
        time += q.top().first;
        answer += time-q.top().second;
        q.pop();
    }
    answer /= jobs.size();
    return answer;
}