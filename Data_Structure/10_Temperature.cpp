#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Heap{
private:
    vector<int> v;
    int siz, dir;
    void swap(int lo, int hi){
        int temp = v[hi];
        v[hi] = v[lo];
        v[lo] = temp;
    }
public:
    Heap(){
        v.push_back(-1);
        siz = 0;
        dir = 0;
    }
    int size(){
        return siz;
    }
    bool isEmpty(){
        return siz==0;
    }
    int pop(){
        if(isEmpty()) return -1;
        swap(1,siz);
        int cur = 1, tmp = v[siz];
        siz--;
        v.pop_back();
        while(true){
            int left = 2*cur, right = left+1;
            if(right <= siz){
                if(v[left] <= v[right]){
                    if(v[left] <= v[cur]){
                        swap(left,cur);
                        cur = left;
                    }else break;
                }else{
                    if(v[right] <= v[cur]){
                        swap(right,cur);
                        cur = right;
                    }else break;
                }
            }else if(left <= siz){
                if(v[left] <= v[cur]){
                    swap(left,cur);
                    cur = left;
                }else break;
            }else break;
        }
        return tmp;
    }
    void insert(int value){
        siz++;
        v.push_back(value);
        if(siz == 1) return;
        int cur = siz, par = siz/2;
        while(cur != 1){
            if(v[cur] <= v[par]){
                swap(cur,par);
                cur = par;
                par /= 2;
            }else break;
        }
    }
    void print(){
        if(siz == 0){
            cout << "-1\n";
            return;
        }
        for(int i = 1; i <= siz; ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    int top(){
        if(siz == 0) return -1;
        return v[1];
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        Heap *pq = new Heap();
        for(int i = 0; i < n; ++i){
            int u;
            cin >> u;
            pq->insert(u);
        }
        int answer = 0;
        while(true){
            if(pq->top() >= m){
                cout << answer << endl;
                pq->print();
                break;
            }
            if(pq->size() == 1){
                cout << "False\n";
                break;
            }
            int tmp = (pq->pop() + pq->pop())/2;
            pq->insert(tmp);
            answer++;
        }
    }
}