#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    for(int i: moves){
        --i;
        for(int j = 0; j < board.size(); ++j){
            if(board[j][i] != 0){
                if(!basket.empty() && basket.top() == board[j][i]){
                    basket.pop();
                    answer += 2;
                }else{
                    basket.push(board[j][i]);
                }
                board[j][i] = 0;
                break;
            }
        }
    }
    return answer;
}