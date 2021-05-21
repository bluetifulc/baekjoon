#include <iostream>
#include <string>
#define NONE 0
#define HAVE 1
#define AVAILABLE 2
using namespace std;

class Entry{
private:
    int key;
    string value;
    int valid;
public:
    Entry(){
        Entry(0,"");
        valid = NONE;
    }
    Entry(int k, string v){
        key = k;
        value = v;
        valid = HAVE;
    }
    void erase(){
        valid = AVAILABLE;
    }
    friend class HashTable;
};
class HashTable{
private:
    Entry* table;
    int N;
    int hashfunc(int key){
        return key%N;
    }
public:
    HashTable(int capa){
        N = capa;
        table = new Entry[N];
    }
    int put(int key, string value){
        int idx = hashfunc(key);
        int cnt = 1;
        while(table[idx].valid == HAVE && cnt <= N){
            cnt++;
            idx = hashfunc(idx+1);
        }
        if(cnt > N) return cnt;
        table[idx] = Entry(key,value);
        return cnt;
    }
    bool erase(int key){
        int idx = hashfunc(key);
        int cnt = 1;
        while(table[idx].valid != NONE && cnt <= N){
            if(table[idx].valid == HAVE && table[idx].key == key){
                table[idx].valid = AVAILABLE;
                return true;
            }
            idx = hashfunc(idx+1);
            cnt++;
        }
        return false;
    }
    string find(int key){
        int idx = hashfunc(key);
        int cnt = 1;
        while(table[idx].valid != NONE && cnt <= N){
            if(table[idx].valid == HAVE && table[idx].key == key){
                return table[idx].value;
            }
            idx = hashfunc(idx+1);
            cnt++;
        }
        return "None";
    }
};

int main(){
    int t,n;
    cin >> t >> n;
    HashTable *ht = new HashTable(n);
    while(t--){
        string oper;
        cin >> oper;
        if(oper == "put"){
            int u;
            string v;
            cin >> u >> v;
            cout << ht->put(u,v) << endl;
        }else if(oper == "find"){
            int u;
            cin >> u;
            cout << ht->find(u)<<endl;
        }else if(oper == "erase"){
            int u;
            cin >> u;
            if(!ht->erase(u)){
                cout << "None\n";
            }
        }
    }
}