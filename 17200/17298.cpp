#include <cstdio>
#include <stack>
using namespace std;
// Stack
int n,nums[1'000'001];
int main(){
    stack<int> st;
    stack<int> result;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &nums[i]);
    }
    for(int i = n-1; i >= 0; --i){
        while(!st.empty() && nums[i] >= st.top()){
            st.pop();
        }
        if(st.empty()) result.push(-1);
        else result.push(st.top());
        st.push(nums[i]);
    }
    while(!result.empty()){
        printf("%d ", result.top());
        result.pop();
    }
    printf("\n");
    return 0;
}