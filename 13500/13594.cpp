#include <cstdio>
#include <queue>
#include <algorithm>
// 13549 숨바꼭질 3
// 0-1 BFS

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int time = 0;
	int dist[100'001];
	bool flag = false;
	std::deque<int> dq;

	std::fill(dist, dist+100001, 123456789);
	dq.push_front(n);
	dist[n] = 0;

	while(!dq.empty()){
		int cur = dq.front();
		dq.pop_front();

		if(cur == k){
			printf("%d\n", dist[k]);
			return 0;
		}
		if(cur*2 <= 100'000 && dist[cur*2] > dist[cur]){
			dist[cur*2] = dist[cur];
			dq.push_front(cur*2);
		}

		if(cur+1 <= 100'000 && dist[cur+1] > dist[cur]+1){
			dist[cur+1] = dist[cur]+1;
			dq.push_back(cur+1);
		}

		if(cur-1 >= 0 && dist[cur-1] > dist[cur]+1){
			dist[cur-1] = dist[cur]+1;
			dq.push_back(cur-1);
		}

	}

	return 0;
}