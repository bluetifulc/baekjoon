#include <cstdio>
#include <algorithm>
using namespace std;
// 공유기 설치
// Binary-Search, Parametric-Search

int main(){
	int n,m,a[200'001];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d",&a[i]);
	}

	sort(a, a+n);

	int lo = 1, hi = 1'000'000'000;
	while(lo <= hi){
		int mid = (lo+hi)/2;

		int last = a[0], cnt = 1;
		for(int i = 1; i < n; ++i){
			if(a[i] - last >= mid){
				++cnt;
				last = a[i];
			}
		}

		if(cnt >= m){
			lo = mid+1;
		}else{
			hi = mid-1;
		}

	}

	printf("%d\n", hi);

	return 0;
}