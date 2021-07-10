#include <iostream>
// 방 번호
// Greedy 
using namespace std;
int main(){
    int n, k, price[10], result[51];
    for(int i = 0; i < 50; ++i){
        result[i] = -1;
    }
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> price[i];
    }
    cin >> k;
    if(n == 1){
        cout << "0\n";
        return 0;
    }

    // 맨앞자리에 넣을 숫자 찾기
    int minIdx = 1;
    for(int i = 2; i < n; ++i){
        if(price[i] <= price[minIdx]){
            minIdx = i;
        }
    }
    if(price[minIdx] > k){ // 0을 제외하곤 살 수 없는 경우
        cout << "0\n";
        return 0;
    }else{
        result[0] = minIdx;
        k -= price[minIdx];
    }
    // 뒤에 채울 숫자 찾기
    if(price[0] < price[minIdx]){
        minIdx = 0;
    }
    
    // 숫자 채우기
    for(int i = 1; k-price[minIdx] >= 0 && i < 50; ++i){
        result[i] = minIdx;
        k -= price[minIdx];
    }

    // 숫자 채운뒤 수를 늘릴 수 있는지 찾기
    for(int i = 0; i < 50; ++i){
        if(result[i] == -1) break;
        for(int j = n-1; j > result[i]; --j){
            if(price[j]-price[result[i]] >= 0 && k - (price[j] - price[result[i]]) >= 0){
                k -= (price[j] - price[result[i]]);
                result[i] = j;
            }
        }
    }

    for(int i = 0; i < 50 && result[i] != -1; ++i){
        cout << result[i];
    }
    cout << endl;
    return 0;
}