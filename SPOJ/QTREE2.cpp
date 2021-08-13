#include <iostream>
#include <vector>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define MAXN 10003
#define LOG 15

int bl[MAXN][LOG], tin[MAXN], tout[MAXN], tmr, d[MAXN], h[MAXN];

class Edge{
public:
    int v, c;
};
vector<Edge> adj[MAXN];

void dfs(int u, int par){
    tin[u] = tmr++;
    bl[u][0] = par;
    for(int i = 1; i < LOG; ++i) bl[u][i] = bl[bl[u][i-1]][i-1];
    for(auto& e:adj[u]) {
        if(e.v != par) {
            h[e.v] = h[u] + 1;
            d[e.v] = d[u] + e.c;
            dfs(e.v, u);
        }
    }
    tout[u] = tmr++;
}

bool isAncestor(int a, int b) {
    return tin[a] < tin[b] && tout[a] > tout[b];
}

int lca(int a, int b){
    if(isAncestor(a, b)) return a;
    if(isAncestor(b, a)) return b;
    for(int i = LOG-1; i >= 0; --i){
        if(!isAncestor(bl[a][i], b)) a = bl[a][i];
    }
    return bl[a][0];
}

int kth(int a, int b, int k){
    --k;
    int x = lca(a, b), y;
    if(k > h[a] - h[x]){
        k = h[b]-h[x]-(k-(h[a]-h[x]));
        y = b;
    } else y = a;

    for(int i = LOG-1; i >= 0 && k > 0; --i){
        if(k >= (1<<i)) {
            k -= (1 << i);
            y = bl[y][i];
        }
    }

    return y;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        tmr = 0;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) adj[i].clear();
        for(int i = 0, u, v, c; i < n-1; ++i){
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        dfs(1, 1);

        char s[10];
        int a, b, k;
        while(1){
            scanf("%s", s);
            if(s[1] == 'O') break;
            if(s[0] == 'D'){
                scanf("%d %d", &a, &b);
                printf("%d\n", a==b?0:d[a]+d[b]-2*d[lca(a,b)]);
            } else{
                scanf("%d %d %d", &a, &b, &k);
                printf("%d\n", kth(a, b, k));
            }
        }
    }
    
    return 0;
}