#include <cstdio>
// 합이 같은 구간
// 부분합 + 약수를 이용한 가지치기
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        bool flag = false;
        int num[10'001], psum[10'001];
        int m;
        scanf("%d",&m);
        for(int i = 0; i < m; ++i){
            scanf("%d",&num[i]);
        }
        psum[0] = num[0];
        for(int i = 1; i < m; ++i){
            psum[i] = psum[i-1]+num[i];
        }
        int result = 1234567890;
        for(int i = 0; i < m; ++i){
            int sum = psum[i], lo = i+1, hi = i+1;
            if(psum[m-1] % psum[i] != 0) continue;
            while(true){
                int cur = psum[hi]-psum[lo-1];
                if(cur < sum){
                    hi++;
                }else if(cur == sum){
                    lo = ++hi;
                    if(lo == m){
                        printf("%d\n", sum);
                        flag = true;
                        break;
                    }
                }else if(cur > sum) break;
            }
            if(flag) break;
        }
        if(!flag) printf("%d\n",psum[m-1]);
    }
    return 0;
}