#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
// 2234 성곽
// BFS, Bit-Masking

int n, m, room[50][50];
int dm[4][2] = {0,-1, -1,0, 0,1, 1,0 };
bool visited[50][50];

int pow2(int a){
	if(a == 0) return 1;
	if(a == 1) return 2;
	if(a == 2) return 4;
	return 8;
}

int bfs(int y, int x){
	int result = 0;
	queue<pair<int,int>> q;

	visited[y][x] = true;
	q.push(make_pair(y,x));

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();

		++result;
		for(int i = 0; i < 4; ++i){
			int ny = y + dm[i][0], nx = x + dm[i][1];
			if(!visited[ny][nx] && (room[y][x] & pow2(i)) != pow2(i)){
				q.push(make_pair(ny,nx));
				visited[ny][nx] = true;
			}
		}
	}
	return result;
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &room[i][j]);
		}
	}

	int result = 0, maximum = 0;

	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(!visited[i][j]){
				++result;
				int cur = bfs(i,j);
				if(cur > maximum) maximum = cur;
			}
		}
	}
	printf("%d\n%d\n", result, maximum);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			for(int k = 0; k < 4; ++k){
				int ny = i+dm[k][0], nx = j+dm[k][1];
				if(ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if((room[i][j] & pow2(k)) == pow2(k)){
					int tmp = room[i][j];
					room[i][j] = (room[i][j] & (~pow2(k)));
					memset(visited, 0, sizeof(visited));
					int cur = bfs(i,j);
					if(cur > maximum) maximum = cur;
					room[i][j] = tmp;
				}
			}
		}
	}
	printf("%d\n", maximum);
	return 0;
}