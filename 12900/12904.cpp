#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 12904 A와 B
// Greedy, String

int main() {
	string a, b;
	cin >> a >> b;

	while(b.size() > 0) {
		if(a == b){
			printf("1\n");
			return 0;
		} 
		if(b.back() == 'A') {
			b = b.substr(0, b.size()-1);
			continue;
		} else if (b.back() == 'B') {
			b = b.substr(0, b.size()-1);
			reverse(b.begin(), b.end());
			continue;
		} else {
			printf("0\n");
			return 0;
		}
	}
	printf("0\n");

	return 0;
}