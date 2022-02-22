#include <cstdio>
#include <vector>
#include <algorithm>
// 1713 후보 추천하기
// Simulation

int main(){
	// who, stars, idx
	int n,m,size=0,f[20][3] = {0,};
	scanf("%d %d", &n, &m);
	for(int idx = 0; idx < m; ++idx){
		int a;
		bool flag = false;
		scanf("%d", &a);
		// 1. 이미 있을경우
		for(int i = 0; i < n; ++i){
			if(f[i][0] == a){
				f[i][1]++;
				flag = true;
				break;
			}
		}
		if(flag) continue;

		// 2. 빈 프레임이 있을 경우
		if(size < n){
			for(int i = 0; i < n; ++i){
				if(f[i][0] == 0){
					f[i][0] = a;
					f[i][1] = 1;
					f[i][2] = idx;
					flag = true;
					++size;
					break;
				}
			}
		}
		if(flag) continue;

		// 3. 빈 프레임이 없을 경우
		std::vector<int> same;
		int mini = 123456789;
		for(int i = 0; i < n; ++i){
			if(f[i][1] == mini){
				same.push_back(i);
			}
			if(f[i][1] < mini){
				same.clear();
				same.push_back(i);
				mini = f[i][1];
			}
		}
		// a) 동점자가 없는 경우
		if(same.size() == 1){
			int b = same[0];
			f[b][0] = a;
			f[b][1] = 1;
			f[b][2] = idx;
			continue;
		}
		// b) 동점자가 있는경우
		int where = -1, minidx = 1001;
		for(int b: same){
			if(f[b][2] < minidx){
				minidx = f[b][2];
				where = b;
			}
		}
		f[where][0] = a;
		f[where][1] = 1;
		f[where][2] = idx;
	}
	
	std::vector<int> result;
	for(int i = 0; i < n; ++i){
		if(f[i][0] == 0) continue;
		result.push_back(f[i][0]);
	}
	std::sort(result.begin(), result.end());
	for(int i: result){
		printf("%d ", i);
	}
	printf("\n");
	
	return 0;
}