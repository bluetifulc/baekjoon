#include <cstdio>
#include <stack>
int main(){
    int n;
    long long result = 0;
    scanf("%d",&n);
    std::stack<std::pair<int,int>> st;
    for(int i = 0; i < n; ++i){
        int a;
        scanf("%d",&a);
        while(!st.empty() && st.top().first < a){
            result += st.top().second;
            st.pop();
        }
        if(st.empty()){
            st.push(std::make_pair(a,1));
        }
        else{
            if(st.top().first != a){
                st.push(std::make_pair(a,1));
                result++;
            }else{
                std::pair<int,int> p = st.top();
                st.pop();
                result += p.second;
                if(!st.empty())
                    result++;
                p.second++;
                st.push(p);
            }
        }
    }
    printf("%lld\n", result);
    return 0;
}