#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
// 11967 불켜기
// BFS

int main(){
	int n, m;
	int dm[4][2] = {0,1, 0,-1, 1,0, -1,0};
	bool visited[101][101] = { 0, };
	bool light[101][101] = { 0, };
	vector<pair<int,int>>  adj[101][101];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u,v,j,k;
		scanf("%d %d %d %d",&u, &v, &j, &k);
		adj[u][v].push_back(make_pair(j,k));
	}
	int result = 1;

	vector<pair<int,int>> now;
	queue<pair<int,int>> q;

	q.push(make_pair(1,1));
	now.push_back(make_pair(1,1));
	visited[1][1] = true;
	light[1][1] = true;
	
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int curx = q.front().first, cury = q.front().second;
			q.pop();
			for(pair<int,int>& p: adj[curx][cury]){
				if(!light[p.first][p.second]){
					light[p.first][p.second] = true;
					++result;
				}
			}
		}

		for(pair<int,int>& p: now){
			int y = p.first, x = p.second;
			for(int i = 0; i < 4; ++i){
				int ny = y + dm[i][0], nx = x +dm[i][1];
				if(ny > 0 && nx > 0 && ny <= n && nx <= n){
					if(!visited[ny][nx] && light[ny][nx]){
						q.push(make_pair(ny,nx));
						now.push_back(make_pair(ny,nx));
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	printf("%d\n", result);

	return 0;
}