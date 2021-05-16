#include <string>
#include <iostream>
#include <vector>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int abs(int a){ return a > 0 ? a : -a; }


class Node{
public:
    Node *left,*right, *par;
    int data;
    Node(){
        Node(0);
    }
    Node(int e){
        left = right = par = nullptr;
        data = e;
    }
    void setLeft(Node* v){
        if(v == nullptr){
            this->left = nullptr;
        }else{
            this->left = v;
            v->par = this;
        }
    }
    void setRight(Node* v){
        if(v == nullptr){
            this->right = nullptr;
        }else{
            this->right = v;
            v->par = this;
        }
    }
};

class AVLTree{
private:
    Node* root;
    int siz;
    void dfs(Node *ptr){
        if(ptr == nullptr) return;
        dfs(ptr->left);
        cout << ptr->data << " ";
        dfs(ptr->right);
    }
public:
    AVLTree(){
        root = nullptr;
        siz = 0;
    }
    Node* rightRotation(Node* ptr){
        Node* temp = ptr->left;
        ptr->setLeft(temp->right);
        temp->setRight(ptr);
        return temp;
    }
    Node* leftRotation(Node* ptr){
        Node* temp = ptr->right;
        ptr->setRight(temp->left);
        temp->setLeft(ptr);
        return temp;
    }
    Node* llCase(Node *ptr){
        return rightRotation(ptr);
    }
    Node* rrCase(Node *ptr){
        return leftRotation(ptr);
    }
    Node* lrCase(Node* ptr){
        Node* left = ptr->left;
        ptr->setLeft(leftRotation(left));
        return rightRotation(ptr);
    }
    Node* rlCase(Node* ptr){
        Node* right = ptr->right;
        ptr->setRight(rightRotation(right));
        return leftRotation(ptr);
    }
    int getHeight(Node* ptr){
        if(ptr == nullptr) return -1;
        return max(getHeight(ptr->left), getHeight(ptr->right))+1;
    }
    int getDiff(Node* ptr){
        if(ptr == nullptr) return 0;
        return getHeight(ptr->left) - getHeight(ptr->right);
    }
    void insert(int e){
        Node* newNode = new Node(e);
        if(root == nullptr){
            root = newNode;
            return;
        }
        vector<Node*> insertPath;
        Node *par = nullptr ,*cur = root;
        while(cur != nullptr){
            par = cur;
            insertPath.push_back(cur);
            if(e > cur->data) cur = cur->right;
            else cur = cur->left;
        }
        if(e > par->data) par->setRight(newNode);
        else par->setLeft(newNode);
        for(int i = insertPath.size()-1; i >= 0; --i){
            Node* tmp = insertPath[i];
            Node* tmpPar = tmp->par;
            // if(i != 0) tmpPar = insertPath[i-1];
            // else tmpPar = nullptr;
            int diff = getDiff(tmp);
            if(abs(diff) > 1){
                Node* where;
                if(diff > 1){
                    if(getDiff(tmp->left) >= 1){ // Left-Left Case
                        where = llCase(tmp);
                    }else{ // Left-Right Case
                        where = lrCase(tmp);
                    }
                }else{
                    if(getDiff(tmp->right) >= 1){ // Right-Left Case
                        where = rlCase(tmp);
                    }else{ // Right-Right Case
                        where = rrCase(tmp);
                    }
                }
                if(i == 0){
                    root = where;
                    where->par = nullptr;
                    break;
                }
                if(tmpPar->left == tmp){ 
                    tmpPar->setLeft(where);
                }
                else{ 
                    tmpPar->setRight(where);
                }
                break;
            }
        }
    }
    Node* search(int e){
        Node* cur = root;
        while(cur != nullptr){
            if(e == cur->data) return cur;
            if(e > cur->data) cur = cur->right;
            else cur = cur->left;
        }
        return nullptr;
    }
    void remove(int e){
        vector<Node*> deletionPath;
        Node* node = root;
        while(node != nullptr){
            deletionPath.push_back(node);
            if(e == node->data) break;
            if(e > node->data) node = node->right;
            else node = node->left;
        }
        Node* par = node->par;
        if(node->left == NULL && node->right == NULL){ // No child
            if(par == NULL){
                root = NULL;
            }
            if(e > par->data) par->setRight(NULL);
            else par->setLeft(NULL);
        }else if(node->left != NULL && node->right == NULL){ // Only Left
            if(par == NULL){
                root = node->left;
                root->par = NULL;
            }
            if(e > par->data) par->setRight(node->left);
            else par->setLeft(node->left);
        }else if(node->left == NULL && node->right != NULL){ // Only Right
            if(par == NULL){
                root = node->right;
                root->par = NULL;
            }
            if(e > par->data) par->setRight(node->right);
            else par->setLeft(node->right);
        }else{ // Two Child
            Node* cur = node->right;
            while(cur->left != NULL){
                deletionPath.push_back(cur);
                cur = cur->left;
            }
            if(cur->par == node){
                node->setRight(cur->right);
            }else cur->par->setLeft(cur->right);
            node->data = cur->data;
        }

        //Balancing
        for(int i = deletionPath.size()-1; i >= 0; --i){
            Node* tmp = deletionPath[i];
            Node* tmpPar = tmp->par;
            int diff = getDiff(tmp);
            if(abs(diff) > 1){
                bool tied = false;
                Node* where;
                int tmpDiff;
                if(diff > 1){
                    if(tmpDiff = getDiff(tmp->left) >= 0){ // Left-Left Case
                        where = llCase(tmp);
                        if(tmpDiff == 0) tied = true;
                    }else{ // Left-Right Case
                        where = lrCase(tmp);
                    }
                }else{
                    if(tmpDiff = getDiff(tmp->right) >= 0){ // Right-Left Case
                        where = rlCase(tmp);
                        if(tmpDiff == 0) tied = true;
                    }else{ // Right-Right Case
                        where = rrCase(tmp);
                    }
                }
                if(i == 0){
                    root = where;
                    where->par = nullptr;
                }else if(tmpPar->left == tmp){ 
                    tmpPar->setLeft(where);
                }
                else{ 
                    tmpPar->setRight(where);
                }
                if(tied) break;
            }
        }

    }
    void DFS(){
        dfs(root);
        cout << endl;
    }
};

int main(){
    AVLTree *tree = new AVLTree();
    int n;
    cin >> n;
    while(n--){
        int u;
        cin >> u;
        tree->insert(u);
        tree->DFS();
    }
    cin >> n;
    while(n--){
        int u;
        cin >> u;
        tree->remove(u);
        tree->DFS();
    }
    
    tree->DFS();
    return 0;
}