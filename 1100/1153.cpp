#include <cstdio>
#include <cmath>
#include <vector>
// 1153 네 개의 소수
// Prime, Mathematics
std::vector<int> prime;
bool isPrime[1'000'001];

int main(){
	int n;
	scanf("%d", &n);
	prime.push_back(2);
	isPrime[2] = true;
	for(int i = 3; i < 1'000'001; ++i){
		bool flag = false;
		for(int j = 2; j < sqrt(i)+1; ++j){
			if(isPrime[j] && i % j == 0){
				flag = true;
				break;
			}
		}
		if(!flag){
			isPrime[i] = true;
			prime.push_back(i);
		}
	}

	if(n < 8){
		printf("-1\n");
	}else{
		if(n % 2 == 0){
			n -= 4;
			for(int i: prime){
				if(n-i > 1 && isPrime[n-i]){
					printf("2 2 %d %d\n", i, n-i);
					break;
				}
			}
		}else{
			n -= 5;
			for(int i: prime){
				if(n-i > 1 && isPrime[n-i]){
					printf("2 3 %d %d\n", i, n-i);
					break;
				}
			}

		}
	}

	return 0;
}