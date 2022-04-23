#include <cstdio>
typedef long long ll;
// 10830 행렬 제곱
// Matrix


ll n,b;

void multiply(ll a[5][5], ll b[5][5]){
	ll result[5][5] = {0,};
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < n; ++j){
			for(ll k = 0; k < n; ++k){
				result[i][j] += a[i][k] * b[k][j];
			}
			result[i][j] %= 1'000;
		}
	}

	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < n; ++j){
			a[i][j] = result[i][j];

		}
	}
}

int main(){
	ll result[5][5] = {0,};
	ll input[5][5];
	scanf("%lld %lld", &n, &b);
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < n; ++j){
			scanf("%lld", &input[i][j]);
		}
	}

	for(ll i = 0; i < n; ++i){
		result[i][i] = 1;
	}

	while(b > 0){
		if(b % 2 == 1){
			multiply(result, input);
		}
		multiply(input, input);

		b /= 2;
	}

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
			printf("%lld ", result[i][j]);
        }
		printf("\n");
    }

	return 0;
}