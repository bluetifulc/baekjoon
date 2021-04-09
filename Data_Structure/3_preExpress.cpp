#include <iostream>
#include <string>
using namespace std;
class Stack{
private:
    int idx,capacity;
    int* arr;
public:
    Stack(int t){
        idx = -1;
        capacity = t;
        arr = new int[t];
    }
    int empty(){
        if(idx == -1) return 1;
        return 0;
    }
    int top(){
        if(empty() == 1) return -1;
        return arr[idx];
    }
    void push(int x){
        if(idx == capacity-1){
            cout << "FULL\n";
            return;
        }
        arr[++idx] = x;
    }
    int pop(){
        if(empty() == 1) return -1;
        return arr[idx--];
    }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        string expression;
        Stack* st = new Stack(15);
        cin >> expression;
        for(int i = 0; i < expression.size(); ++i){
            char now = expression[i];
            if('1' <= now && now <= '9'){
                st->push(now-'0');
                continue;
            }
            int v = st->pop(), u = st->pop();
            if(now == '+'){
                st->push(u+v);
            }else if(now == '-'){
                st->push(u-v);
            }else if(now == '*'){
                st->push(u*v);
            }else if(now == '/'){
                st->push(u/v);
            }
        }
        cout << st->pop()%10 << endl;
    }
    return 0;
}