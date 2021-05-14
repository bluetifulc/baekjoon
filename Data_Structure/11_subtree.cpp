#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
public:
    Node *left, *right, *par;
    int data;
    Node(int n){
        data = n;
        left = right = par = NULL;
    }
    void setLeft(Node* v){
        if(v == NULL){
            this->left = NULL;
        }else{
            this->left = v;
            v->par = this;
        }
    }
    void setRight(Node* v){
        if(v == NULL){
            this->right = NULL;
        }else{
            this->right = v;
            v->par = this;
        }
    }
};

class BST{
public:
    Node* root;
    BST(){
        root = NULL;
    }
    void insert(int e){
        Node* newNode = new Node(e);
        if(root == NULL){
            root = newNode;
            return;
        }
        Node* par = NULL;
        Node* cur = root;
        while(cur != NULL){
            if(e > cur->data){
                par = cur;
                cur = cur->right;
            }else{
                par = cur;
                cur = cur->left;
            }
        }
        if(e > par->data) par->setRight(newNode);
        else if(e < par->data) par->setLeft(newNode);
    }
    Node* search(int e){
        Node* cur = root;
        while(cur != NULL){
            if(e == cur->data) return cur;
            if(e > cur->data) cur = cur->right;
            else cur = cur->left;
        }
        return NULL;
    }
    void remove(int e){
        Node* node = search(e);
        Node* par = node->par;
        if(node->left == NULL && node->right == NULL){ // No child
            if(par == NULL){
                root = NULL;
                return;
            }
            if(e > par->data) par->setRight(NULL);
            else par->setLeft(NULL);
        }else if(node->left != NULL && node->right == NULL){ // Only Left
            if(par == NULL){
                root = node->left;
                node->par = NULL;
                return;
            }
            if(e > par->data) par->setRight(node->left);
            else par->setLeft(node->left);
        }else if(node->left == NULL && node->right != NULL){ // Only Right
            if(par == NULL){
                root = node->right;
                node->par = NULL;
                return;
            }
            if(e > par->data) par->setRight(node->right);
            else par->setLeft(node->right);
        }else{ // Two Child
            Node* cur = node->right;
            while(cur->left != NULL){
                cur = cur->left;
            }
            if(cur->par == node){
                node->setRight(cur->right);
            }else cur->par->setLeft(cur->right);
            node->data = cur->data;
        }
    }
    int sub(int e){
        Node* cur = search(e);
        if(cur == NULL) return 0;
        return dfs(cur);
    }
    int dfs(Node* cur){
        int tmp = 0;
        if(cur->left != NULL) tmp += dfs(cur->left);
        if(cur->right != NULL) tmp += dfs(cur->right);
        return tmp+1;
    }
};

int main(){
    int t;
    cin >> t;
    string oper;
    BST *bst = new BST();
    while(t--){
        cin >> oper;
        if(oper == "insert"){
            int u;
            cin >> u;
            bst->insert(u);
        }else if(oper == "delete"){
            int u;
            cin >> u;
            bst->remove(u);
        }else if(oper == "sub"){
            int u;
            cin >> u;
            cout << bst->sub(u) << endl;
        }
    }
    return 0;
}