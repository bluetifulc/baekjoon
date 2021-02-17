#include <cstdio>
#define ll long long
#define MAX 1'000'000
// Segment Tree
ll num[MAX], tree[MAX*4];
int n,m,k;
ll init(int node, int start, int end){
    if(start == end) return tree[node] = num[start];
    int mid = (start+end)/2;
    return tree[node] = init(node*2,start,mid)+init(node*2+1,mid+1,end);
}

ll sum(int node, int start, int end, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return sum(node*2,start,mid,left,right)+sum(node*2+1,mid+1,end,left,right);
}

void update(int node, int start, int end, int index, ll diff){
    if(start > index || end < index) return;
    tree[node] += diff;
    if(start == end) return;
    int mid = (start+end)/2;
    update(node*2,start,mid,index,diff);
    update(node*2+1,mid+1,end,index,diff);
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; ++i){
        scanf("%lld",&num[i]);
    }
    init(1,0,n-1);
    for(int i = 0; i < m+k; ++i){
        int a,b;
        scanf("%d%d",&a,&b);
        b--;
        if(a==1){
            ll c;
            scanf("%lld",&c);
            update(1,0,n-1,b,c-num[b]);
            num[b] = c;
        }else{
            int c;
            scanf("%d",&c);
            c--;
            printf("%lld\n", sum(1,0,n-1,b,c));
        }
    }
    return 0;
}