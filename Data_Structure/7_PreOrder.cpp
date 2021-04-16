#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node* parent;
    vector<Node*> children;
    Node(int elem){
        data = elem;
        parent = NULL;
    }
};
class Tree{
private:
    Node* root;
    vector<Node*> nodes;
public:
    Tree(int data){
        root = new Node(data);
        root->parent = new Node(0);
        nodes.push_back(root);
    }
    Node* getRoot(){
        return root;
    }
    void insert(int par, int data){
        Node* newNode = new Node(data);
        nodes.push_back(newNode);
        for(int i = 0; i < nodes.size(); ++i){
            if(nodes[i]->data == par){
                newNode->parent = nodes[i];
                nodes[i]->children.push_back(newNode);
                return;
            }
        }
    }
    void preOrder(Node* node){
        cout << node->parent->data << " ";
        for(Node* next:node->children){
            preOrder(next);
        }
    }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        Tree* tree = new Tree(1);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int u,v;
            cin >> u >> v;
            tree->insert(u,v);
        }
        tree->preOrder(tree->getRoot());
        cout << "\n";
    }
}