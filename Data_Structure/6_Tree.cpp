#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node{
public:
    Node* parent;
    int data;
    vector<Node*> children;
    Node(int elem){
        data = elem;
        parent = NULL;
    }
};

class Tree{
public:
    Node* root;
    vector<Node*> nodes;
    Tree(int elem){
        Node* newNode = new Node(elem);
        root = newNode;
        nodes.push_back(newNode);
    }
    void insert(int x,int y){
        for(int i = 0; i < nodes.size(); ++i){
            if(nodes[i]->data == x){
                Node* newNode = new Node(y);
                nodes.push_back(newNode);
                nodes[i]->children.push_back(newNode);
                newNode->parent = nodes[i];
                return;
            }
        }
        cout << "-1\n";
    }
    void remove(int x){
        for(int i = 0; i < nodes.size(); ++i){
            if(nodes[i]->data == x){
                if(nodes[i] == root){
                    cout << "-1\n";
                    return;
                }
                Node* parent = nodes[i]->parent;
                for(Node* child: nodes[i]->children){
                    child->parent = parent;
                    parent->children.push_back(child);
                }
                for(int j = 0; j < parent->children.size(); ++j){
                    if(parent->children[j]->data == x){
                        parent->children.erase(parent->children.begin() + j);
                    }
                }
                Node* cur = nodes[i];
                nodes.erase(nodes.begin() + i);
                delete cur;
                return;
            }
        }
        cout << "-1\n";
    }
    void print(int x){
        for(int i = 0; i < nodes.size(); ++i){
            if(nodes[i]->data == x){
                if(nodes[i]->children.empty()){
                    cout << "-1\n";
                    return;
                }
                for(Node* child: nodes[i]->children){
                    cout << child->data << " ";
                }
                cout << endl;
                return;
            }
        }
        cout << "-1\n";
    }
};

int main(){
    int n;
    cin >> n;
    Tree* tree = new Tree(1);
    while(n--){
        string oper;
        cin >> oper;
        if(oper == "insert"){
            int x,y;
            cin >> x >> y;
            tree->insert(x,y);
        }else if(oper == "delete"){
            int x;
            cin >> x;
            tree->remove(x);
        }else if(oper == "print"){
            int x;
            cin >> x;
            tree->print(x);
        }
    }
    return 0;
}