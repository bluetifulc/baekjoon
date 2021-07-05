#include <iostream>
#include <string>
// 검열
// String
using namespace std;
int main(){
    string a,t;
    cin >> a >> t;
    int alen = a.length();
    int lo = 0, hi = t.length() - alen - 1;
    while(true){
        bool flag = false;
        int tlen = t.length();
        for(int i = lo; i < tlen-alen; ++i){
            if(t.substr(i,alen) == a){
                t.erase(i,alen);
                flag = true;
                if(i - alen*2 <= 0) lo = 0;
                else lo = i - alen*2;
                break;
            }
        }
        if(!flag) break;
        tlen = t.length();
        if(hi >= tlen) hi = tlen-1;
        flag = false;
        for(int i = hi; i >= 0; --i){
            if(t.substr(i,alen) == a){
                t.erase(i,alen);
                flag = true;
                hi = i;
                break;
            }
        }
        if(!flag) break;
    }
    cout << t << endl;
    return 0;
}