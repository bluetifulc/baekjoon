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
                root->par = NULL;
                return;
            }
            if(e > par->data) par->setRight(node->left);
            else par->setLeft(node->left);
        }else if(node->left == NULL && node->right != NULL){ // Only Right
            if(par == NULL){
                root = node->right;
                root->par = NULL;
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
    int findLeftMost(){
        Node* cur = root;
        while(cur->left != NULL){
            cur = cur->left;
        }
        int tmp = cur->data;
        remove(tmp);
        return tmp;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        BST *bst = new BST();
        for(int i = 0; i < n; ++i){
            int u;
            cin >> u;
            bst->insert(u);
        }
        int v;
        cin >> v;
        while(v >= 2){
            bst->findLeftMost();
            v--;
        }
        cout << bst->findLeftMost() << endl;
    }
    return 0;
}