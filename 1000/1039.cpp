#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;
// 교환
// String, BFS

int main(){
    string n;
    int k;
    cin >> n >> k;
    
    int m = n.length();
    
    int time = 0;
    string result = "0";
    queue<string> q;
    q.push(n);
    while(!q.empty() && time != k){
        set<string> visited;
        int qSize = q.size();
        while(qSize--){
            string cur = q.front();
            q.pop();
            for(int i = 0; i < m; ++i){
                for(int j = i+1; j < m; ++j){
                    if(i == 0 && cur[j] == '0'){
                        continue;
                    }
                    swap(cur[i], cur[j]);
                    if(visited.find(cur) == visited.end()){
                        if(time == k-1 && result < cur){
                            result = cur;
                        }
                        q.push(cur);
                        visited.insert(cur);
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }
        ++time;
    }

    if(time == k && result != "0"){
        cout << result << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}