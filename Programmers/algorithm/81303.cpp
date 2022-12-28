#include <string>
#include <vector>
#include <stack>
// 표 편집
// Linked-List
using namespace std;

struct Node{
    Node* prev;
    Node* next;
    int n;
    Node(int n, Node* prev) : n(n), prev(prev), next(NULL) {};
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    int x;
    
    struct Node* mak = new Node(0, NULL);
    struct Node* cur = mak;
    for(int i = 1; i < n; ++i) {
        mak->next = new Node(i, mak);
        mak = mak->next;
    }
    for(int i = 0; i < k; ++i){
        cur = cur->next;
    }
    stack<struct Node*> st;
    for(string& oper: cmd){
        switch(oper[0]){
            case 'U':
                x = stoi(oper.substr(2));
                for(int i = 0; i < x; ++i){
                    cur = cur->prev;
                }
                break;
            case 'D':
                x = stoi(oper.substr(2));
                for(int i = 0; i < x; ++i){
                    cur = cur->next;
                }
                break;
            case 'C':
                st.push(cur);
                if(cur->next != NULL){
                    cur->next->prev = cur->prev;
                }
                if(cur->prev != NULL){
                    cur->prev->next = cur->next;
                }
                if(cur->next != NULL){
                    cur = cur->next;
                }else{
                    cur = cur->prev;
                }
                break;
            case 'Z':
                struct Node* z = st.top();
                st.pop();
                if(z->next != NULL){
                    z->next->prev = z;
                }
                if(z->prev != NULL){
                    z->prev->next = z;
                }
                break;
        }
    }
    while(cur->prev != NULL){
        cur = cur->prev;
    }
    while(cur->next != NULL){
        answer[cur->n] = 'O';
        cur = cur->next;
    }
    answer[cur->n] = 'O';
    return answer;
}