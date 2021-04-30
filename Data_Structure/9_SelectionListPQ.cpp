#include <iostream>
#include <vector>
using namespace std;
class isGreater{
public:
    bool operator()(const int& left, const int& right){
        return left > right;   
    }
};

class PQ{
private:
    vector<int> v;
public:
    void insert(int e){
        v.push_back(e);
    }
    int removeMax(){
        vector<int>::iterator q = v.begin();
        isGreater cmp;
        for(vector<int>::iterator p = v.begin(); p != v.end(); ++p){
            if(cmp(*p,*q)){
                q = p;
            }
        }
        int temp = *q;
        v.erase(q);
        return temp;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        PQ pq;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int u;
            cin >> u;
            pq.insert(u);
        }
        for(int i = 0; i < n; ++i){
            cout << pq.removeMax() << " ";
        }
        cout << endl;
    }
    return 0;
}