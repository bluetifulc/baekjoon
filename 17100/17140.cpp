#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 이차원 배열과 연산
// Sorting, Simulation

int cnt[101];
int A[101][101];
int hr = 3, hc = 3;

bool compare(int a, int b){
    if(cnt[a] == cnt[b]){
        return a < b;
    }
    return cnt[a] < cnt[b];
}

void calc_rc(){
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            if(A[i][j] != 0){
                hr = max(hr, j);
                hc = max(hc, i);
            }
        }
    }
}

void r_sort(){
    vector<int> v[101];
    for(int i = 0; i < 100; ++i){
        fill(cnt, cnt+101, 0);
        for(int j = 0; j < 100; ++j){
            cnt[A[i][j]]++;
        }

        int tmp[100];
        for(int j = 1; j <= 100; ++j){
            tmp[j-1] = j;
        }
        sort(tmp, tmp+100, compare);

        for(int j = 0; j < 100; ++j){
            if(cnt[tmp[j]] != 0){
                v[i].push_back(tmp[j]);
                v[i].push_back(cnt[tmp[j]]);
            }
        }
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            if(j < v[i].size()){
                A[i][j] = v[i][j];
            }else{
                A[i][j] = 0;
            }
        }
    }
}

void c_sort(){
    size_t result = 0;
    vector<int> v[101];
    for(int i = 0; i < 100; ++i){
        fill(cnt, cnt+101, 0);
        for(int j = 0; j < 100; ++j){
            cnt[A[j][i]]++;
        }

        int tmp[100];
        for(int j = 1; j <= 100; ++j){
            tmp[j-1] = j;
        }
        sort(tmp, tmp+100, compare);

        for(int j = 0; j < 100; ++j){
            if(cnt[tmp[j]] != 0){
                v[i].push_back(tmp[j]);
                v[i].push_back(cnt[tmp[j]]);
            }
        }
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            if(j < v[i].size()){
                A[j][i] = v[i][j];
            }else{
                A[j][i] = 0;
            }
        }
    }
}

int main(){
    int r,c,k;
    
    cin >> r >> c >> k;
    r--; c--;
    
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i <= 100; ++i){
        if(A[r][c] == k){
            cout << i << "\n";
            return 0;
        }
        calc_rc();
        if(hr <= hc){
            r_sort();
        }else{
            c_sort();
        }
    }

    cout << "-1\n";

    return 0;
}