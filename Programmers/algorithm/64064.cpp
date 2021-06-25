#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <set>
//불량 사용자
//Bit-Masking, Regex, DFS
using namespace std;
int n,m;
bool check[8][8] = {0,};
bool visited[8] = {0,};
set<int> s;
void dfs(int idx){
    if(idx == n){
        int c = 1;
        int sum = 0;
        for(int i = 0; i < m; ++i){
            if(visited[i]){
                sum += c*(i+1);
            }
            c *= 10;
        }
        if(s.find(sum) == s.end()){
            s.insert(sum);
        }
        return;
    }
    
    for(int i = 0; i < m; ++i){
        if(check[idx][i] && !visited[i]){
            visited[i] = true;
            dfs(idx+1);
            visited[i] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    n = banned_id.size();
    m = user_id.size();
    for(int i = 0; i < n; ++i){
        string str = banned_id[i];
        for(int j = 0; j < str.length(); ++j){
            if(str[j] == '*') str[j] = '.';
        }
        regex reg(str);
        for(int j = 0; j < m; ++j){
            check[i][j] = regex_match(user_id[j],reg);
        }
    }
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j){
    //         cout << check[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    dfs(0);
    answer = s.size();
    // set<int>::iterator iter = s.begin();
    // for(; iter!=s.end(); ++iter){
    //     cout << *iter << endl;
    // }
    return answer;
}

int main(){
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "abc1**"};
    cout << solution(user_id,banned_id) << endl;
    return 0;
}