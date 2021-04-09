#include <iostream>
#include <string>
using namespace std;
class Node{
    int data;
    Node* next;
    Node(){
        Node(0);
    }
    Node(int x){
        data = x;
        next = nullptr;
    }
    friend class Queue;
};
class Queue{
private:
    Node *f, *r;
    int s;
public:
    Queue(){
        f = nullptr;
        r = nullptr;
        s = 0;
    }
    bool isEmpty(){
        return f == nullptr;
    }
    int size(){
        return s;
    }
    void enqueue(int x){
        Node* newNode = new Node(x);
        if(isEmpty()){
            f = newNode;
            r = newNode;
            s++;
            return;
        }
        r->next = newNode;
        r = newNode;
        s++;
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Empty\n";
        }else{
            s--;
            cout << f->data << endl;
            Node* tmp = f;
            f = f->next;
            delete tmp;
        }
    }
    void front(){
        if(isEmpty()){
            cout << "Empty\n";
        }else{
            cout << f->data << endl;
        }
    }
    void rear(){
        if(isEmpty()){
            cout << "Empty\n";
        }else{
            cout << r->data << endl;
        }
    }
};
int main(){
    int t;
    Queue *q = new Queue();
    cin >> t;
    while(t--){
        string oper;
        cin >> oper;
        if(oper == "isEmpty"){
            if(q->isEmpty()){
                cout << "True\n";
            }else{
                cout << "False\n";
            }
        }else if(oper == "size"){
            cout << q->size() << endl;
        }else if(oper == "dequeue"){
            q->dequeue();
        }else if(oper == "enqueue"){
            int u;
            cin >> u;
            q->enqueue(u);
        }else if(oper == "front"){
            q->front();
        }else if(oper == "rear"){
            q->rear();
        }
    }
    return 0;
}