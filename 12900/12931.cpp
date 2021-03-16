#include <cstdio>
using namespace std;
// Greedy
int main(){
    int n, now,arr[50];
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&arr[i]);
    }
    int result = 0;
    while(true){
        bool flag = true;
        for(int i = 0; i < n; ++i){
            if(arr[i] != 0){
                flag = false;
                break;
            }
        }
        if(flag) break;
        flag = true;
        for(int i = 0; i < n; ++i){
            if(arr[i] % 2 == 1){
                arr[i]--;
                flag = false;
                break;
            }
        }
        if(flag){
            for(int i = 0; i < n; ++i){
                arr[i] /= 2;
            }
        }
        result++;
    }
    printf("%d\n", result);
    return 0;
}