#include <cstdio>
#include <queue>
using namespace std;
int A,B,C,D;
int emptyA[100'001];
int emptyB[100'001];
int fullA[100'001];
int fullB[100'001];
struct point{
    int a,b,cnt;
    point(int p,int q,int r):a(p),b(q),cnt(r){}
    point():point(0,0,0){}
};
bool visit(int _a,int _b, int _cnt){
    bool flag = false;
    if(_a == 0 && emptyA[_b]==0){
        emptyA[_b]=_cnt;
        flag = true;
    }
    if(_b == 0 && emptyB[_a]==0){
        emptyB[_a]=_cnt;
        flag = true;
    }
    if(_a == A && fullA[_b]==0){
        fullA[_b]=_cnt;
        flag = true;
    }
    if(_b == B && fullB[_a]==0){
        fullB[_a]=_cnt;
        flag = true;
    }
    if(flag) return true;
    return false;
}
int main(){
    int result = -1;
    queue<point> q;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    q.push(point(0,0,0));
    while(!q.empty()){
        int nowA = q.front().a, nowB = q.front().b, nowCnt = q.front().cnt;
        q.pop();
        if(nowA == C && nowB == D){
            if(nowA == 0) result = emptyA[nowB];
            if(nowB == 0) result = emptyB[nowA];
            if(nowA == A) result = fullA[nowB];
            if(nowB == B) result = fullB[nowA];
            break;
        }

        if(visit(A,nowB,nowCnt+1)) q.push(point(A,nowB,nowCnt+1));
        if(visit(nowA,B,nowCnt+1)) q.push(point(nowA,B,nowCnt+1));
        if(visit(0,nowB,nowCnt+1)) q.push(point(0,nowB,nowCnt+1));
        if(visit(nowA,0,nowCnt+1)) q.push(point(nowA,0,nowCnt+1));
        int sum = nowA + nowB;
        if(A < sum){
            if(visit(A,sum-A,nowCnt+1)) q.push(point(A,sum-A,nowCnt+1));
        }else{
            if(visit(sum,0,nowCnt+1)) q.push(point(sum,0,nowCnt+1));
        }
        if(B < sum){
            if(visit(sum-B,B,nowCnt+1)) q.push(point(sum-B,B,nowCnt+1));
        }else{
            if(visit(0,sum,nowCnt+1)) q.push(point(0,sum,nowCnt+1));
        }
    }
    if(result == -1) printf("-1\n");
    else printf("%d\n", result);
    return 0;
}