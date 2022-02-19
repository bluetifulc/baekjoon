#include <cstdio>
#include <stack>

int main(){
	int n, p, result = 0;
	std::stack<int> st[7];
	scanf("%d %d", &n, &p);

	for(int i = 0; i < n; ++i){
		int a,b;
		scanf("%d %d", &a, &b);
		while(true){
			if(!st[a].empty() && b == st[a].top()){
				break;
			}
			if(st[a].empty() || b >= st[a].top()){
				st[a].push(b);
				++result;
				break;
			}
			st[a].pop();
			++result;
		}
	}
	printf("%d\n", result);
	return 0;
}