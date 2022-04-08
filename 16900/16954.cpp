#include <iostream>
#include <string>
#include <queue>
using namespace std;
// 16954 움직이는 미로 탈출
// BFS

int main(){
	string map[8];
	for(int i = 0; i < 8; ++i){
		cin >> map[i];
	}
	
	int dm[9][2] = { 0,1, 0,-1, 1,0, -1,0, 0,0, 1,-1, -1,1, 1,1, -1,-1 };
	queue<pair<int,int>> q;
	bool end = false;
	q.push(make_pair(7,0));
	while(!q.empty()){
		bool visited[8][8] = { 0, };
		int qSize = q.size();
		while(qSize--){
			int y = q.front().first, x = q.front().second;
			q.pop();

			if(y == 0 && x == 7){
				end = true;
				break;
			}

			if(map[y][x] == '#')
				continue;

			for(int i = 0; i < 9; ++i){
				int ny = y+dm[i][0], nx = x+dm[i][1];
				if(ny >= 0 && nx >= 0 && ny < 8 && nx < 8){
					if(!visited[ny][nx] && map[ny][nx] == '.'){
						q.push(make_pair(ny,nx));
						visited[ny][nx] = true;
					}
				}
			}
		}
		
		if(end)
			break;

		// 벽 이동
		for(int i = 7; i >= 1; --i){
			for(int j = 0; j < 8; ++j){
				map[i][j] = map[i-1][j];
			}
		}
		for(int i = 0; i < 8; ++i){
			map[0][i] = '.';
		}

	}

	cout << end << endl; 
	return 0;
}