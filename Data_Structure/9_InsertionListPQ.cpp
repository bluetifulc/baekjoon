#include <iostream>
#include <vector>
using namespace std;
class isLess{
public:
    bool operator()(const int& left, const int& right){
        return left < right;   
    }
};

class PQ{
private:
    vector<int> v;
public:
    void insert(int e){
        isLess cmp;
        vector<int>::iterator p = v.begin();
        if(v.empty()){
            v.insert(p, e);
        }else{
            while(p != v.end() && cmp(e, *p)){
                ++p;
            }
            v.insert(p,e);
        }
    }
    int removeMin(){
        int temp = v.back();
        v.pop_back();
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
            cout << pq.removeMin() << " ";
        }
        cout << endl;
    }
    return 0;
}