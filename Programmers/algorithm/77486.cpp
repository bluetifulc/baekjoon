#include <string>
#include <vector>
#include <map>

// 다단계 칫솔 판매
// Brute Force - Recurrence

using namespace std;

int par[10'001];
int result[10'001];
map<string, int> m;

void recur(int cur, int money){
    int parmoney = money / 10;
    int curmoney = money - parmoney;
    result[cur] += curmoney;
    if(parmoney == 0 || par[cur] == 0){
        return;
    }
    recur(par[cur], parmoney);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    m.insert({"-", 0});
    for(int i = 0; i < enroll.size(); ++i){
        m.insert({enroll[i], i+1});
    }
    for(int i = 0; i < referral.size(); ++i){
        par[i+1] = m[referral[i]];
    }
    for(int i = 0; i < seller.size(); ++i){
        recur(m[seller[i]], amount[i] * 100);
    }
    for(int i = 1; i <= enroll.size(); ++i){
        answer.push_back(result[i]);
    }
    return answer;
}