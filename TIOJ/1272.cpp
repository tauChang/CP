/*
 tag: segment tree, bit, tree flattening, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 100010
int st[MAXN << 3], in[MAXN], out[MAXN], timer=0;
vector<int> g[MAXN];

void dfs(int i){
    in[i] = timer++;
    for(auto& j:g[i]) dfs(j);
    out[i] = timer++;
}

void modify(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) {
        st[id] ^= 1;
        return;
    }
    int tm = (tl+tr)/2;
    if(r <= tm) modify(id*2+1, tl, tm, l, r);
    else if(l > tm) modify(id*2+2, tm+1, tr, l, r);
    else {
        modify(id*2+1, tl, tm, l, tm);
        modify(id*2+2, tm+1, tr, tm+1, r);
    }
}

int query(int id, int tl, int tr, int x){
    if(tl == tr) return st[id];
    st[id*2+1] ^= st[id];
    st[id*2+2] ^= st[id];
    st[id] = 0;
    int tm = (tl+tr)/2;
    if(x <= tm) return query(id*2+1, tl, tm, x);
    return query(id*2+2, tm+1, tr, x);
}

int main(){
    AC
    int n, m;
    cin >> n >> m;
    for(int i = 1, cnt, j; i <= n; ++i){
        cin >> cnt;
        while(cnt--) {
            cin >> j;
            g[i].push_back(j);
        }
    }
    dfs(1);

    int a, b;
    while(m--){
        cin >> a >> b;
        if(!a) modify(0, 0, timer-1, in[b], out[b]);
        else cout << query(0, 0, timer-1, in[b]) << endl;
    }

}