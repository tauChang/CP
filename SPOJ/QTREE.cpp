#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define LOG 14
using namespace std;
 
class Edge{
    public:
    int v, c;
};
 
vector<Edge> adj[10003];
int map[10003][2];
int bl[10003][LOG], tin[10003], tout[10003]; // lca
int sz[10003], arrPos[10003], head[10003]; // hld
int st[40009], arr[10003]; // segment tree
int counter, pos, n;
 
void dfs(int u, int par){
    tin[u] = counter++;
    sz[u] = 1;
    bl[u][0] = par;
    for(int i = 1; i < LOG; ++i) bl[u][i] = bl[bl[u][i-1]][i-1];
    for(auto& e:adj[u]) {
        if(e.v != par) {
            dfs(e.v, u);
            sz[u] += sz[e.v];
        }
    }
    tout[u] = counter++;
}
 
void hld(int u, int par, int hd, int val){
    head[u] = hd;
    arrPos[u] = pos;
    arr[pos++] = val;
 
    int hv, hsz=-1, hc;
    for(auto& e:adj[u]){
        if(e.v != par && sz[e.v] > hsz){
            hv = e.v;
            hsz = sz[e.v];
            hc = e.c;
        }
    }
 
    if(hsz == -1) return; //leaf node
    hld(hv, u, hd, hc);
    for(auto& e:adj[u]){
        if(e.v != hv && e.v != par) hld(e.v, u, e.v, e.c);
    }
}
 
void build(int id, int tl, int tr){
    // printf("%d %d\n", tl, tr);
    if(tl == tr) {
        st[id] = arr[tl];
        return;
    }
    int tm = (tl + tr)/2;
    build(id*2+1, tl, tm);
    build(id*2+2, tm+1, tr);
    st[id] = max(st[id*2+1], st[id*2+2]);
}
 
void update(int id, int tl, int tr, int x, int v){
    if(tl == x && tr == x) { 
        st[id] = v;
        return;
    }
    int tm = (tl+tr)/2;
    if(x <= tm) update(id*2+1, tl, tm, x, v);
    else if(x > tm) update(id*2+2, tm+1, tr, x, v);
    st[id] = max(st[id*2+1], st[id*2+2]);
}
 
int query(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) return st[id];
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, tl, tm, l, r);
    else if(l > tm) return query(id*2+2, tm+1, tr, l, r);
    else return max(query(id*2+1, tl, tm, l, tm), query(id*2+2, tm+1, tr, tm+1, r));
}
 
bool isAncestor(int x, int y){
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}
 
int lca(int x, int y){
    if(isAncestor(x, y)) return x;
    if(isAncestor(y, x)) return y;
    for(int i = LOG-1; i >= 0; --i){
        // printf("lca: %d %d\n", x, y);
        if(!isAncestor(bl[x][i], y)) x = bl[x][i];
    }
    return bl[x][0];
}
 
int queryUp(int x, int target){
    int ans = 0;
    while(x != target){
        if(head[x] == head[target]) {
            ans = max(ans, query(0, 0, n-1, arrPos[target]+1, arrPos[x]));
            break;
        }
        ans = max(ans, query(0, 0, n-1, arrPos[head[x]], arrPos[x]));
        x = bl[head[x]][0];
    }
    return ans;
}
 
int main(){
    AC
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) adj[i].clear();
        for(int i = 1, u, v, c; i <= n-1; ++i) {
            scanf("%d %d %d", &u, &v, &c);
            map[i][0] = u; map[i][1] = v;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
 
        counter = 0;
        dfs(1, 1);
        pos = 0;
        hld(1, 1, 1, -1);
        build(0, 0, n-1);
        // for(int i = 1; i <= n; ++i){
        //     for(int j = 1; j <= n; ++j) printf("%d %d lca is %d\n", i, j, lca(i, j));
        // }
 
        char s[10];
        int a, b;
        while(1){
            scanf("%s", s);
            if(s[0] == 'D') break;
            scanf("%d %d", &a, &b);
            if(s[0] == 'Q') {
                int x = lca(a, b);
                printf("%d\n", max(queryUp(a, x), queryUp(b, x)));
            }else if(s[0] == 'C') {
                int u = map[a][0], v = map[a][1];
                update(0, 0, n-1, max(arrPos[u], arrPos[v]), b);
            }
        }
    }
    return 0;
} 