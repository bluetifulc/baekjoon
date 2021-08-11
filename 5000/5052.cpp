#include <iostream>
#include <string>
// 전화번호 목록
// Trie
using namespace std;

string str;
int len;
struct Trie{
    Trie* go[10];
    bool end;
    bool haveGo;
    Trie(){
        for(int i = 0; i < 10; ++i) go[i] = nullptr;
        end = haveGo = false;
    }
    ~Trie(){
        for(int i = 0; i < 10; ++i)
            if(go[i] != nullptr) delete go[i];
    }
    void insert(int idx){
        if(idx == len) end = true;
        else{
            int next = str[idx]-'0';
            if(go[next] == nullptr){
                go[next] = new Trie();
            }
            haveGo = true;
            go[next]->insert(idx+1);
        }
    }
    bool consistent(){
        if(haveGo && end) return false;
        for(int i = 0; i < 10; ++i){
            if(go[i]!=nullptr && !go[i]->consistent()) return false;
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Trie *root = new Trie();
        for(int i = 0; i < n; ++i){
            cin >> str;
            len = str.size();
            root->insert(0);
        }
        if(root->consistent()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        delete root;
    }
    return 0;
}