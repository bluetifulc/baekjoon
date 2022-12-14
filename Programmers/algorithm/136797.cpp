#include <string>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
// 숫자 타자 대회
// DP

inline int min(int a, int b){ return ( a > b ? b : a); }

const int digit[10][10] = { 
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};
int n;
string nums;
int cache[100'002][10][10] = { 0, };

int dp(int cur, int l, int r){
    if(cur == n){
        return 0;
    }
    int& ref = cache[cur][l][r];
    if(ref != -1){
        return ref;
    }
    int goal = nums[cur]-'0';
    if(goal == l){
        return ref = 1 + dp(cur+1, l, r);
    }else if(goal == r){
        return ref = 1 + dp(cur+1, l, r);
    }
    return ref = min(digit[l][goal] + dp(cur+1, goal, r), digit[r][goal] + dp(cur+1, l, goal));
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(string numbers) {
    memset(cache, -1, sizeof(cache));
    n = numbers.size();
    nums = numbers;

    return dp(0, 4, 6);
}