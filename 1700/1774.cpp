#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
// 우주신과의 교감
// MST(Kruskal)
int p[1001];
int find(int a){
    if(p[a]==-1)return a;
    return p[a] = find(p[a]);
}
bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    p[b]=a;
    return true;
}
struct edge{
    int u,v;
    double w;
    edge(int a,int b,double c):u(a),v(b),w(c){}
    edge():edge(0,0,0){}
    bool operator<(const edge& right){
        return w<right.w;
    }
};

int main(){
    int n,m,coord[1001][2];
    scanf("%d %d",&n,&m);
    std::vector<edge> edges;
    for(int i = 1; i <= n; ++i){
        p[i]=-1;
        scanf("%d %d",&coord[i][0],&coord[i][1]);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            double dx = pow(coord[i][0]-coord[j][0],2);
            double dy = pow(coord[i][1]-coord[j][1],2);
            double dist = sqrt(dx+dy);
            edges.push_back(edge(i,j,dist));
        }
    }
    std::sort(edges.begin(),edges.end());
    for(int i = 0; i < m; ++i){
        int u,v;
        scanf("%d %d",&u,&v);
        merge(u,v);
    }
    double result = 0;
    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].u, v = edges[i].v;
        double w = edges[i].w;
        if(merge(u,v)){
            result+=w;
        }
    }
    printf("%.2lf\n", result);
    return 0;
}