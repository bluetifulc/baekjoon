#include <bits/stdc++.h>
// 마법의 엘리베이터
// Math

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey > 0){
        int c = storey % 10;
        int d = (storey / 10) % 10;
        if(c > 5){
            answer += 10-c;
            storey += 10;
        }else if(c < 5){
            answer += c;
        }else{
            if(d >= 5){
                answer += 5;
                storey += 10;
            }else{
                answer += 5;
            }
        }
        storey /= 10;
    }
    return answer;
}