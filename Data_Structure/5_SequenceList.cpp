#include <iostream>
#include <string>
using namespace std;
class SequenceList{
private:
    struct Node{
        int value;
        Node *prev, *next;
    };
public:
    class Iterator{
    private:
        Node* node;
        Iterator(Node* u){
            node = u;
        }
    public:
        int& operator*(){
            return node->value;
        }
        bool operator==(const Iterator& right) const{
            return node == right.node;
        }
        bool operator!=(const Iterator& right) const{
            return node != right.node;
        }
        Iterator& operator++(){
            node = node->next;
            return *this;
        }
        Iterator& operator--(){
            node = node->prev;
            return *this;
        }
        friend class SequenceList;
    };

private:
    int n;
    Node* header;
    Node* trailer;
public:
    SequenceList(){
        n = 0;
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
    }
    int size() const{
        return n;
    }
    bool empty() const{
        return size()==0;
    }
    Iterator begin() const{
        return Iterator(header->next);
    }
    Iterator end() const{
        return Iterator(trailer);
    }
    void insert(const Iterator& p, int elem){
        Node *curr = p.node;
        Node *prev = curr->prev;
        Node *newNode = new Node;
        newNode->value = elem;
        newNode->next = curr;
        curr->prev = newNode;
        prev->next = newNode;
        newNode->prev = prev;
        this->n++;
    }
    void erase(const Iterator& p){
        if(empty()){
            cout << "Empty\n";
            return;
        }
        Node *curr = p.node;
        Node *next = curr->next;
        Node *prev = curr->prev;
        prev->next = next;
        next->prev = prev;
        delete curr;
        this->n--;
    }
    void insertFront(const int& e){
        insert(begin(), e);
    }
    void insertBack(const int& e){
        insert(end(), e);
    }
    void eraseFront(const int& e){
        erase(begin());
    }
    void eraseBack(const int& e){
        erase(--end());
    }
    void print(){
        if(empty()){
            cout << "Empty\n";
            return;
        }
        Iterator iter = begin();
        for(; iter!=end(); ++iter){
            cout << iter.node->value << " ";
        }
        cout << endl;
    }
    void find(const int& e){
        if(empty()){
            cout << "Empty\n";
            return;
        }
        int idx = 0;
        Iterator iter = begin();
        for(; iter!=end(); ++iter, ++idx){
            if(iter.node->value == e){
                cout << idx << endl;
                return;
            }
        }
        cout << "-1\n";
    }
};

int main(){
    int m;
    string oper;
    cin >> m;
    SequenceList list;
    SequenceList::Iterator iter = list.begin();
    while(m--){
        cin >> oper;
        if(oper == "find"){
            int u;
            cin >> u;
            list.find(u);
        }else if(oper == "print"){
            list.print();
        }else if(oper == "insert"){
            int u;
            cin >> u;
            list.insert(iter, u);
        }else if(oper == "erase"){
            list.erase(iter);
            iter = list.begin();
        }else if(oper == "begin"){
            iter = list.begin();
        }else if(oper == "end"){
            iter = list.end();
        }else if(oper == "++"){
            ++iter;
        }else if(oper == "--"){
            --iter;
        }
    }
    return 0;
}