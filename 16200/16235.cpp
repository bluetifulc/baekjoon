#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 나무재테크
// Simulation

int dm[8][2] = { 0,1, 0,-1, 1,0, -1,0, 1,1, -1,1, -1,-1, 1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k,a[10][10],b[10][10];
    vector<int> tree[10][10];
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            a[i][j] = 5;
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < m; ++i){
        int x,y,year;
        cin >> x >> y >> year;
        tree[x-1][y-1].push_back(year);
    }

    while(k--){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                // 봄
                vector<int> new_tree;
                int death = 0;
                sort(tree[i][j].begin(), tree[i][j].end());
                for(int k = 0; k < tree[i][j].size(); ++k){
                    if(a[i][j] >= tree[i][j][k]){
                        new_tree.push_back(tree[i][j][k]+1);
                        a[i][j] -= tree[i][j][k];
                    }else{
                        death += tree[i][j][k] / 2;
                    }
                }
                tree[i][j] = new_tree;
                // 여름
                a[i][j] += death;
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                // 가을
                for(int k = 0; k < tree[i][j].size(); ++k){
                    if(tree[i][j][k] % 5 == 0){
                        for(int h = 0; h < 8; ++h){
                            int dy = i + dm[h][0], dx = j + dm[h][1];
                            if(dy >= 0 && dx >= 0 && dy < n && dx < n){
                                tree[dy][dx].push_back(1);
                            }
                        }
                    }
                }
                // 겨울
                a[i][j] += b[i][j];
            }
        }
    }

    int result = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            result += tree[i][j].size();
        }
    }
    cout << result << endl;

    return 0;
}