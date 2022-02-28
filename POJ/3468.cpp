/*
 tag: BIT, RMQ, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 100005
#define lc id*2+1
#define rc id*2+2
typedef long long ll;
ll a[MAXN], st[MAXN << 2], tag[MAXN << 2], sz[MAXN << 2];
int n, q;

void build(int id, int tl, int tr){
    sz[id] = tr-tl+1;
    if(tl == tr) {
        st[id] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(lc, tl, tm);
    build(rc, tm+1, tr);
    st[id] = st[lc] + st[rc];
}

ll rv(int id){
    return st[id]+tag[id]*sz[id];
}

void push(int id){
    tag[lc] += tag[id];
    tag[rc] += tag[id];
    st[id] += tag[id] * sz[id];
    tag[id] = 0;
}

void add(int id, int tl, int tr, int l, int r, int v){
    if(tl == l && tr == r) {
        tag[id] += v;
        return;
    }
    int tm = (tl + tr) / 2;
    if(r <= tm) add(lc, tl, tm, l, r, v);
    else if(l > tm) add(rc, tm+1, tr, l, r, v);
    else {
        add(lc, tl, tm, l, tm, v);
        add(rc, tm+1, tr, tm+1, r, v);
    }
    st[id] = rv(lc)+rv(rc);
}

ll query(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) return rv(id);
    push(id);
    int tm = (tl + tr) / 2;
    if(r <= tm) return query(lc, tl, tm, l, r);
    if(l > tm) return query(rc, tm+1, tr, l, r);
    return query(lc, tl, tm, l, tm) + query(rc, tm+1, tr, tm+1, r) + (r-l+1)*tag[id];
}

int main(){
    AC
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    build(0, 0, n-1);

    char t;
    int l, r;
    ll v;
    while(q--){
        cin >> t;
        if(t == 'Q') {
            cin >> l >> r;
            cout << query(0, 0, n-1, l-1, r-1) << endl;
        } else{
            cin >> l >> r >> v;
            add(0, 0, n-1, l-1, r-1, v);
        }
    }
}