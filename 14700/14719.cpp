#include <cstdio>
// 14719 빗물
// Implementation 구현

inline int min(int a, int b){ return a > b ? b : a; }

int main(){
	int h,w,block[501] = { 0, };
	scanf("%d %d", &h, &w);
	for(int i = 0; i < w; ++i){
		scanf("%d", &block[i]);
	}
	
	int result = 0;
	for(int i = 1; i < w-1; ++i){
		int cur = block[i], lmax = 0, rmax = 0;
		for(int j = i-1; j >= 0; --j){
			if(block[j] > lmax){
				lmax = block[j];
			}
		}
		for(int j = i+1; j < w; ++j){
			if(block[j] > rmax){
				rmax = block[j];
			}
		}
		int height = min(lmax, rmax);
		if(cur >= height)
			continue;
		result += height-cur;
	}
	printf("%d\n", result);

	return 0;
}