#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool exist[2001];
int matrix[2001][2001];
int main(){
    int t,n;
    cin >> t >> n;
    for(int i = 0; i < n; ++i){
        int u;
        cin >> u;
        exist[u] = true;
    }
    while(t--){
        string oper;
        cin >> oper;
        if(oper == "insertEdge"){
            int u,v;
            cin >> u >> v;
            if(matrix[u][v] == 1){
                cout << "Exist\n";
                continue;
            }
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }else if(oper == "eraseEdge"){
            int u,v;
            cin >> u >> v;
            if(matrix[u][v] == 0){
                cout << "None\n";
                continue;
            }
            matrix[u][v] = 0;
            matrix[v][u] = 0;
        }else if(oper == "isAdjacentTo"){
            int u,v;
            cin >> u >> v;
            if(matrix[u][v] == 1){
                cout << "True\n";
            }else{
                cout << "False\n";
            }
        }
    }
}