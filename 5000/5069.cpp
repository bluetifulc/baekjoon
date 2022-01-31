#include <cstdio>
// 5069 미로에 갇힌 상근
// DP

int dp[40][40][15];

int dm[6][2] = { 0,1,0,-1,1,0,-1,0,1,-1,-1,1 };

int solve(int y, int x, int time){
	if(time == 0){
		if(y == 15 && x == 15)
			return 1;
		else
			return 0;
	}
	int& ref = dp[y][x][time];
	if(ref != -1)
		return ref;
	ref = 0;
	for(int i = 0; i < 6; ++i){
		int ny = y+dm[i][0];
		int nx = x+dm[i][1];
		ref += solve(ny, nx, time-1);
	}
	return ref;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i = 0; i < 40; ++i){
		for(int j = 0; j < 40; ++j){
			for(int k = 0; k < 15; ++k){
				dp[i][j][k] = -1;
			}
		}
	}
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n", solve(15, 15, n));
	}
	return 0;
}