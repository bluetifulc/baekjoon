#include <cstdio>
// 최대공약수와 최대공배수
// Euclidean Algorithm

int gcd(int a, int b){
	while(b){
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int a,b;
	scanf("%d %d", &a, &b);

	printf("%d\n%d\n", gcd(a,b), a*b/gcd(a,b));

	return 0;
}