#include <iostream>
#include <vector>
using namespace std;


int nums[1'001], depth[1'001], where[1'001] = { 0 , };
vector<int> tree[1'001];
void printPre(int idx){
    cout << nums[idx] << " ";
    for(int child: tree[idx]){
        printPre(child);
    }
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
        for(int i = 0; i < n-1; ++i){ 
            if(where[depth[i]-1] == 0 || where[depth[i]-1] <= i){
                for(int j = i+1; j < n; ++j){
                    if(depth[j] == depth[i]-1){
                        where[depth[j]] = j;
                        break;
                    }
                }
            }
            // cout << where[depth[i]-1] << ", " << i << endl;
            tree[where[depth[i]-1]].push_back(i);
        }
        printPre(n-1);
        cout << endl;
    }
}