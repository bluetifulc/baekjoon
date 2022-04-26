#include <cstdio>
#include <algorithm>
#define MINF -123456789
inline int max(int a, int b){ return a > b ? a : b; }
// 2228 구간 나누기
// DP(Recursive)
int n, m, arr[100];
int psum[100];
int cache[100][100];


int dp(int idx, int remain){
	if(remain == 0)
		return 0;
	if(idx >= n && remain != 0)
		return MINF*10;
	int& ref = cache[idx][remain];
	if(ref != MINF){
		return ref;
	}
	ref = dp(idx+1, remain); // 그냥 넘기는 경우
	for(int i = idx; i < n; ++i){
		ref = max(ref, (psum[i+1]-psum[idx]) + dp(i+2, remain-1));
	}
	return ref;
}


int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < n; ++i){
		psum[i+1] = psum[i]+arr[i];
	}
	for(int i = 0; i < 100; ++i){
		for(int j = 0; j < 100; ++j){
			cache[i][j] = MINF;
		}
	}
	printf("%d\n", dp(0, m));
	return 0;
}
