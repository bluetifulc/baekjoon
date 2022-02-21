#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 123456789
#define P pair<int,int>
using namespace std;
inline int min(int a,int b){ return a > b ? b : a; }
// 1504 특정한 최단 경로
// Dijkstra

vector<pair<int,int>> adj[801];

int dijkstra(int src, int dst){
	int dist[801];
	bool visited[801] = { 0, };
	fill(dist, dist+801, INF);
	priority_queue<P, vector<P>, greater<P>> pq;

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while(!pq.empty()){
		int cur, w;
		do{
			cur = pq.top().second;
			w = pq.top().first;
			pq.pop();
		}while(!pq.empty() && visited[cur]);
		if(visited[cur]) break;

		for(P& p: adj[cur]){
			int next = p.second, weight = p.first;
			if(dist[next] > w + weight){
				dist[next] = w + weight;
				pq.push(make_pair(dist[next], next));
			}
		}

	}

	if(dist[dst] == INF){
		return -1;
	}else{
		return dist[dst];
	}

}


int main(){

	int n, e;
	scanf("%d %d", &n, &e);

	for(int i = 0; i < e; ++i){
		int u,v,w;
		scanf("%d %d %d", &u, &v, &w);
		adj[v].push_back(make_pair(w,u));
		adj[u].push_back(make_pair(w,v));
	}

	int v1, v2;
	scanf("%d %d", &v1, &v2);

	int oneToV1 = dijkstra(1, v1);
	int v1ToV2 = dijkstra(v1, v2);
	int v2ToN = dijkstra(v2, n);

	int oneToV2 = dijkstra(1, v2);
	int v2ToV1 = dijkstra(v2, v1);
	int v1ToN = dijkstra(v1, n);

	int result = INF;
	if(oneToV1 != -1 && v1ToV2 != -1 && v2ToN != -1){
		result = min(result, oneToV1+v1ToV2+v2ToN);
	}
	if(oneToV2 != -1 && v2ToV1 != -1 && v1ToN != -1){
		result = min(result, oneToV2+v2ToV1+v1ToN);
	}

	if(result == INF){
		printf("-1\n");
	}else{
		printf("%d\n", result);
	}

	return 0;
}