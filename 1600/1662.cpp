#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 1662 압축
// Stack

int main(){
	string input;
	cin >> input;
	
	stack<int> st;

	for(int i = 0; i < input.length(); ++i){
		if(input[i] != ')'){
			st.push(input[i]);
		}else{
			int c = 0;
			while(!st.empty()){
				int cur = st.top();
				st.pop();
				if(cur == '('){
					break;
				}else if(cur < 0){ // 압축해제하여 길이를 넣은 경우
					c += -cur;
				}else{ // input의 기본 숫자(하나의 문자 추가)
					c++;
				}
			}

			int multiplier = st.top() - '0';
			st.pop();
			if(multiplier != 0 && c != 0){
				st.push(-c * multiplier);
			}

		}
	}

	int result = 0;
	while(!st.empty()) {
		int cur = st.top();
		st.pop();
		if (cur < 0) result += -cur;
		else result++;
	}
	cout << result << endl;

	return 0;
}