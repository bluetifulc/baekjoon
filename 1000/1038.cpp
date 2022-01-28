#include<cstdio>
#include <queue>
// 1038 감소하는 수
// Queue
int main() {
	long long n, m = 0, i = 0;
	std::queue<long long> q;
	scanf("%lld", &n);

	for(int i = 0; i <= 9; ++i){
		q.push(i);
	}

	while(true){
		if(q.empty()){
			printf("-1\n");
			return 0;
		}
		m = q.front();
		q.pop();
		int tmp = m%10;
		for(int j = 0; j < tmp; ++j){
			q.push(m*10+j);
		}

		if(n == i)
			break;
		++i;
	}
	printf("%lld\n", m);
	return 0;
}