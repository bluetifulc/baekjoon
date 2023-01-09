#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 숫자 카드 나누기
// Math - GCD

int gcd(int a, int b){
    if(b > a){
        int c = a;
        a = b;
        b = c;
    }
    while(b != 0){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcda = arrayA[0];
    int gcdb = arrayB[0];
    for(int i = 1; i < arrayA.size(); ++i){
        gcda = gcd(gcda, arrayA[i]);
    }
    for(int i = 1; i < arrayB.size(); ++i){
        gcdb = gcd(gcdb, arrayB[i]);
    }

    for(int i = 0; i < arrayA.size(); ++i){
        if(arrayA[i] % gcdb == 0){
            gcdb = 0;
            break;
        }
    }
    for(int i = 0; i < arrayB.size(); ++i){
        if(arrayB[i] % gcda == 0){
            gcda = 0;
            break;
        }
    }

    return max(gcda,gcdb);
}