#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(){
    int n,k;
    long long result = 0;
    queue<int> q[21];
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        string name;
        cin >> name;
        int len = name.length();
        while(!q[len].empty() && q[len].front()+k < i){
            q[len].pop();
        }
        result += q[len].size();
        q[len].push(i);
    }
    cout << result << endl;
    return 0;
}