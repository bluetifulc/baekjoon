#include <cstdio>
#include <algorithm>
using namespace std;
// 수 찾기
// Binary Search

int main(){
    int n, a[100'001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int m;
    scanf("%d", &m);
    while(m--){
        int s;
        scanf("%d", &s);
        bool flag = false;
        int lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(a[mid] == s){
                flag = true;
                break;
            }
            if(a[mid] > s){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        if(flag){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    return 0;
}