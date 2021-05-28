#include <iostream>
#include <string>
#include <vector>
using namespace std;

int matrix[501][501];
int canGroup[501][501];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> matrix[i][j];
            canGroup[i][j] = matrix[i][j];
            if(matrix[i][j] == 0) canGroup[i][j] = 123456789;
            if(i == j) canGroup[i][j] = 0;
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(canGroup[i][j] > canGroup[i][k]+canGroup[k][j])
                    canGroup[i][j] = canGroup[i][k]+canGroup[k][j];
            }
        }
    }
    while(m--){
        int k;
        vector<int> v;
        cin >> k;
        for(int i = 0; i < k; ++i){
            int u;
            cin >> u;
            v.push_back(u);
        }
        bool flag = true;
        for(int i = 0; i < k; ++i){
    
            for(int j = 0; j < k; ++j){
                if(i == j) continue;
                if(canGroup[v[i]][v[j]] >= 3){
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true) cout << "1\n";
        else cout << "0\n";
    }
    // for(int i = 1; i <= n; ++i){
    //     for(int j = 1; j <= n; ++j){
    //         cout << canGroup[i][j];
    //     }
    //     cout << endl;
    // }
    return 0;
}