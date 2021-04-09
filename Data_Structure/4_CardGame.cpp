#include <iostream>
using namespace std;
class Queue{
private:
    int* arr;
    int capacity,f,r;
public:
    Queue(int x){
        arr = new int[x+1];
        capacity = x+1;
        f = 0;
        r = 0;
    }
    bool isEmpty(){
        return (f == r);
    }
    bool isFull(){
        return ((r+1)%capacity) == f;
    }
    int size(){
        return (r+capacity-f)%capacity;
    }
    void enqueue(int x){
        if(isFull()) return;
        r = (r+1)%capacity;
        arr[r] = x;
    }
    int dequeue(){
        if(isEmpty()) return -1;
        f = (f+1)%capacity;
        return arr[f];
    }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int u;
        cin >> u;
        Queue *qOne = new Queue(u);
        Queue *qTwo = new Queue(u);
        for(int i = 0; i < u; ++i){
            int v;
            cin >> v;
            qOne->enqueue(v);
        }
        for(int i = 0; i < u; ++i){
            int v;
            cin >> v;
            qTwo->enqueue(v);
        }
        int score = 0;
        int hpOne = 0, hpTwo = 0;
        for(int i = 0; i < u; ++i){
            hpOne += qOne->dequeue();
            hpTwo += qTwo->dequeue();
            if(hpOne > hpTwo){
                hpOne -= hpTwo;
                hpTwo = 0;
                score++;
            }else if(hpOne < hpTwo){
                hpTwo -= hpOne;
                hpOne = 0;
                score--;
            }else{
                hpOne = 0;
                hpTwo = 0;
            }
        }
        if(score > 0) cout << "1\n";
        else if(score < 0) cout << "2\n";
        else cout << "0\n";
    }
    return 0;
}