#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// Back-Tracking

int n,k,answer;
string words[51];
bool educated[26];

void solve(int idx, int cnt){
    if(cnt == k-5){
        int temp = 0;
        for(int i = 0; i < n; ++i){
            bool flag = false;
            for(int j = 0; j < words[i].length(); ++j){
                if(educated[words[i][j] - 'a'] == false){
                    flag = true;
                    break;
                }
            }
            if(!flag) temp++;
        }
        if(temp > answer) answer = temp;
        return;
    }
    for(int i = idx; i < 26; ++i){
        if(!educated[i]){
            educated[i] = true;
            solve(i+1,cnt+1);
            educated[i] = false;
        }
    }
}

int main(){
    scanf("%d%d",&n,&k);
    if(k < 5){
        printf("0\n");
        return 0;
    }
    if(k == 26){
        printf("%d\n",n);
        return 0;
    }
    for(int i = 0; i < n; ++i){
        cin >> words[i];
        words[i] = words[i].substr(4,words[i].length()-8);
    }
    educated['a'-'a']=true;
    educated['c'-'a']=true;
    educated['i'-'a']=true;
    educated['n'-'a']=true;
    educated['t'-'a']=true;
    solve(0,0);
    printf("%d\n", answer);
    return 0;
}