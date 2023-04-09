#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 이모티콘 할인행사
// Back-tracking

int maxi = 0, money = 0;
int emo[10];
int rate[4] = { 40, 30, 20, 10 };

void check(vector<vector<int>>& users, vector<int>& emoticons){
    int cur = 0;
    int curMoney = 0;
    for(vector<int>& user: users){
        int userMoney = 0;
        for(int i = 0; i < emoticons.size(); ++i){
            if(emo[i] >= user[0]){
                userMoney += emoticons[i] * (100 - emo[i]) / 100;
            }
        }
        if(userMoney >= user[1]){
            ++cur;
        }else{
            curMoney += userMoney;
        }
    }
    
    if(cur > maxi){
        maxi = cur;
        money = curMoney;
    }else if(cur == maxi){
        if(curMoney >= money){
            maxi = cur;
            money = curMoney;
        }
    }
}

void dfs(vector<vector<int>>& users, vector<int>& emoticons, int depth){
    if(depth == emoticons.size()){
        check(users, emoticons);
        return;
    }
    for(int i = 0; i < 4; ++i){
        emo[depth] = rate[i];
        dfs(users, emoticons, depth+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    dfs(users, emoticons, 0);
    answer.push_back(maxi);
    answer.push_back(money);
    return answer;
}