#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 애너그램
// String, Back-tracking

int alpha[26];
int str_size;
string output;
void dfs(int idx){
    if(idx == str_size){
        cout << output << "\n";
    }
    for(int i = 0; i < 26; ++i){
        if(alpha[i] > 0){
            alpha[i]--;
            output.push_back(i+'a');
            dfs(idx+1);
            alpha[i]++;
            output.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        fill(alpha, alpha+26, 0);
        string input;
        cin >> input;
        
        str_size = input.size();
        for(int i = 0; i < str_size; ++i){
            alpha[input[i]-'a']++;
        }

        dfs(0);
    }
    return 0;
}