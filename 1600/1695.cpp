#include <cstdio>
#include <cstring>
// 1695 펠린드롬 만들기
// DP
inline int min(int a, int b){ return a > b ? b : a; }

int n, num[5000];
int dp[5000][5000];

int solve(int x, int y){
	if(x >= y)
		return 0;
	
	int &ref = dp[x][y];
	if(ref != -1)
		return ref;
	
	if(num[x] == num[y]){
		return ref = solve(x+1, y-1);
	}else{
		return ref = min(solve(x+1,y)+1, solve(x,y-1)+1);
	}

}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d",&num[i]);
	}
	memset(dp, -1, sizeof(dp));

	printf("%d\n", solve(0,n-1));
	return 0;
}