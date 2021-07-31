#include <cstdio>
// 색종이 만들기
// Divide & Conquer
int n, map[129][129];
int blue = 0, white = 0;
void check(int ay, int ax, int by, int bx){
    int first = map[ay][ax];
    for(int i = ay; i <= by; ++i){
        for(int j = ax; j <= bx; ++j){
            if(first != map[i][j]){
                first = -1;
                break;
            }
        }
        if(first == -1) break;
    }
    if((ay==by && ax==bx) || first != -1){
        if(first == 1) ++blue;
        else ++white;
        // printf("(%d, %d) (%d, %d):%d\n", ay,ax,by,bx, first);
        return;
    }
    int midy = (ay+by)/2;
    int midx = (ax+bx)/2;
    check(ay,ax,midy,midx);
    check(midy+1,ax,by,midx);
    check(ay,midx+1,midy,bx);
    check(midy+1,midx+1,by,bx);
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    check(0,0,n-1,n-1);
    printf("%d\n%d\n", white, blue);

}