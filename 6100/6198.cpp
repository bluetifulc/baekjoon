#include <cstdio>
#include <stack>
int main(){
    int n;
    long long result = 0;
    std::stack<int> s;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int a;
        scanf("%d",&a);
        if(s.empty()){
            s.push(a);
            continue;
        }
        while(!s.empty() && s.top() <= a){
            s.pop();
        }
        result += s.size();
        s.push(a);
    }
    printf("%lld\n", result);
    return 0;
}