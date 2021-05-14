#include <string>
#include <iostream>
#include <vector>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int abs(int a){ return a > 0 ? a : -a; }


class Node{
public:
    Node *left,*right;
    int data;
    Node(){
        left = right = nullptr;
        data = 0;
    }
};

class AVLTree{
private:
    Node* root;
    int siz;
public:
    AVLTree(){
        root = nullptr;
        siz = 0;
    }
    Node* llRotation(Node* ptr){
        Node* temp = ptr->left;
        ptr->left = temp->right;
        temp->right = ptr;
        return temp;
    }
    Node* rrRotation(Node* ptr){
        Node* temp = ptr->right;
        ptr->right = temp->left;
        temp->left = ptr;
        return temp;
    }
    Node* lrRoation(Node* ptr){
        Node* lchild = ptr->left;
        Node* rchild = lchild->right;
        lchild->right = rchild->left;
        ptr->left = rchild->right;
        rchild->right = ptr;
        rchild->left = ptr;
        return rchild;
    }
    Node* rlRoation(Node* ptr){
        Node* rchild = ptr->right;
        Node* lchild = rchild->left;
        lchild->left = rchild->right;
        ptr->right = rchild->left;
        lchild->left = ptr;
        lchild->right = rchild;
        return rchild;
    }
    int getHeight(Node* ptr){
        if(ptr == nullptr) return -1;
        return max(getHeight(ptr->left), getHeight(ptr->right))+1;

    }
};