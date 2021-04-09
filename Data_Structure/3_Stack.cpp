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
    int t,n;
    cin >> t >> n;
    Stack* st = new Stack(t);
    while(n--){
        string oper;
        cin >> oper;
        if(oper == "empty"){
            cout << st->empty() << endl;
        }else if(oper == "top"){
            cout << st->top() << endl;
        }else if(oper == "push"){
            int w;
            cin >> w;
            st->push(w);
        }else if(oper == "pop"){
            cout << st->pop() << endl;
        }
    }
    return 0;
}