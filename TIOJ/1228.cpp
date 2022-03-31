/*
 tag: bit, tree flattening, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 1000006

vector<int> g[MAXN];
int n, q, timer=1, in[MAXN], out[MAXN], val[MAXN], bit[MAXN<<1];

void dfs(int u){
    in[u] = timer++;
    for(auto& v:g[u]){
        dfs(v);
    }
    out[u] = timer++;
}

void add(int x, int val){
    for(; x <= (n<<1); x += x&-x) bit[x] += val;
}

int query(int x){
    int ans = 0;
    for(; x; x -= x&-x) ans += bit[x];
    return ans;
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n-1; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].push_back(v);
        val[v] = t;
    }
    dfs(0);
    for(int u = 0; u < n; ++u) {
        add(in[u], val[u]);
        add(out[u], val[u]);
    }
    int type, u, t;
    while(q--){
        scanf("%d %d", &type, &u);
        if(!type){
            scanf("%d", &t);
            add(in[u], t - val[u]);
            add(out[u], t - val[u]);
            val[u] = t;
        } else{
            if(in[u] == out[u]-1) printf("%d\n", 0);
            else printf("%d\n", query(out[u]-1) - query(in[u]));
        }
    }
    return 0;
}