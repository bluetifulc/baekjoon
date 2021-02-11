#include <iostream>
using namespace std;
// SegmentTree
int nums[100'001],tree[400'004];

int init(int node, int start, int end){
    if(start == end) return tree[node] = nums[start];
    int mid = (start+end)/2;
    return tree[node] = init(node*2,start,mid)*init(node*2+1,mid+1,end);
}

int per(int node, int start, int end, int left,int right){
    if(start > right || end < left) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return per(node*2,start,mid,left,right)*per(node*2+1,mid+1,end,left,right);
}

int update(int node, int start, int end, int index, int value){
    if(index > end || index < start) return tree[node];
    if(start == end){
        return tree[node] = value;
    }
    int mid = (start+end)/2;
    return tree[node] = update(node*2,start,mid,index,value)*update(node*2+1,mid+1,end,index,value);
}

int main(){
    int n,k;
    bool first = false;
    while(cin>>n>>k){
        if(!first){
            first = true;
        }else{
            printf("\n");
        }
        for(int i = 0; i < n; ++i){
            int t;
            scanf("%d",&t);
            if(t > 0) t = 1;
            else if(t < 0) t = -1;
            nums[i] = t;
        }
        init(1,0,n-1);
        for(int i = 0; i < k; ++i){
            char oper;
            int u,v;
            scanf(" %c%d%d", &oper,&u,&v);
            if(oper == 'P'){
                u--;v--;
                int w = per(1,0,n-1,u,v);
                if(w == 0) printf("0");
                else if(w == 1) printf("+");
                else if(w == -1) printf("-");
            }else{
                u--;
                if(v > 0) v = 1;
                else if(v < 0) v = -1;
                update(1,0,n-1,u,v);
            }
        }
    }
    return 0;
}