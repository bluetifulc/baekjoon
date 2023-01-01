#include <iostream>
// 기차여행
// P-Sum

using namespace std;

long long p[100'001], a[100'001], b[100'001], c[100'001];
long long psum[100'001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 0; i < m-1; ++i){
        if(p[i] <= p[i+1]){
            psum[p[i]]++;
            psum[p[i+1]]--;
        }else{
            psum[p[i+1]]++;
            psum[p[i]]--;
        }
    }

    // cout << psum[0] << " ";
    for(int i = 1; i < n; ++i){
        psum[i] += psum[i-1];
        // cout << psum[i] << " "; 
    }
    // cout << "\n";

    long long res = 0;
    for(int i = 0; i < n; ++i){
        if(psum[i] == 0){
            continue;
        }
        if(psum[i] * a[i] > c[i] + psum[i] * b[i]){
            res += c[i] + psum[i] * b[i];
            // cout << "BUY IC " << c[i] + psum[i] * b[i] << "\n";
        }else{
            res += psum[i] * a[i];
            // cout << "BUY TICKET " << psum[i] * a[i] << "\n";
        }
    }
    cout << res << "\n";

    return 0;
}