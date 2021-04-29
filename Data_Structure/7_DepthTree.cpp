#include <iostream>
#include <vector>
using namespace std;
//풀이 1

int nums[1'001], depth[1'001], where[1'001] = { 0 , };
vector<int> tree[1'001];
void printPost(int idx){
    for(int child: tree[idx]){
        printPost(child);
    }
    cout << nums[idx] << " ";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            tree[i].clear();
            where[i] = 0;
            cin >> nums[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> depth[i];
        }
        where[0] = 0;
        for(int i = 1; i < n; ++i){ 
            where[depth[i]] = i;
            // cout << where[depth[i]-1] << "," << i <<endl;
            tree[where[depth[i]-1]].push_back(i);
        }
        printPost(0);
        cout << endl;
    }
}
// 풀이2
// #include <iostream>
// #include <vector>
// using namespace std;
// class Node{
// public:
//     int data;
//     Node* parent;
//     vector<Node*> children;
//     Node(int elem){
//         data = elem;
//         parent = NULL;
//     }
// };
// class Tree{
// private:
//     Node* root;
//     vector<Node*> nodes;
// public:
//     Tree(int data){
//         root = new Node(data);
//         root->parent = new Node(0);
//         nodes.push_back(root);
//     }
//     Node* getRoot(){
//         return root;
//     }
//     void insert(int par, int data){
//         Node* newNode = new Node(data);
//         nodes.push_back(newNode);
//         for(int i = 0; i < nodes.size(); ++i){
//             if(nodes[i]->data == par){
//                 newNode->parent = nodes[i];
//                 nodes[i]->children.push_back(newNode);
//                 return;
//             }
//         }
//     }
//     void postOrder(Node* node){
//         for(Node* next:node->children){
//             postOrder(next);
//         }
//         cout << node->data << " ";
//     }   
// };
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         Tree* tree = new Tree(1);
//         int nums[1'001] = { 0, };
//         int stack[1'001] = { 0, };
//         stack[0] = 1;
//         int back = 0;
//         int n;
//         cin >> n;
//         for(int i = 0; i < n; ++i){
//             cin >> nums[i];
//         }
//         int depth;
//         cin >> depth;
//         for(int i = 1; i < n; ++i){
//             cin >> depth;
//             if(depth == back){
//                 tree->insert(stack[--back], nums[i]);
//                 stack[++back] = nums[i];
//                 continue;
//             }else if(depth == back+1){
//                 tree->insert(stack[back], nums[i]);
//                 stack[++back] = nums[i];
//                 continue;
//             }
//             back = depth-1;
//             tree->insert(stack[back], nums[i]);
//             stack[++back] = nums[i];
//         }
//         tree->postOrder(tree->getRoot());
//         cout << "\n";
//     }
// }

