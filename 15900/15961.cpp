#include <cstdio>
// 15961 회전초밥
// Two-Pointer
int dish[3'000'001];
int now[3001];
int main(){
	int n,d,k,c, maxi=0;
	scanf("%d %d %d %d", &n, &d, &k, &c);
	for(int i = 0; i < n; ++i){
		scanf("%d", &dish[i]);
	}
	for(int i = 0; i < k; ++i){
		if(!now[dish[i]]++){
			++maxi;
		}
	}
	if(!now[c])
		++maxi;

	int cnt = maxi;
	int lo = 1, hi = (lo+k-1)%n;
	for(; lo < n; ++lo){
		if(!--now[dish[lo-1]]){
			--cnt;
			if(dish[lo-1] == c){
				++cnt;
			}
		}
		if(!now[dish[hi]]++){
			++cnt;
			if(dish[hi] == c){
				--cnt;
			}
		}
		if(cnt > maxi){
			maxi = cnt;
		}
		// printf("%d~%d: %d\n", lo, hi, cnt);
		hi = (hi+1)%n;
	}
	printf("%d\n",maxi);

	return 0;
}