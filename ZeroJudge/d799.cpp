/*
 tag: segment tree
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
#define MAXN 500005
ll a[MAXN];

class Node{
public:
    ll v = 0, tag = 0, sz = 0;
    ll rv(){
        return v + tag*sz;
    }
} st[MAXN<<2];

void build(int id, int tl, int tr){
    if(tl == tr){
        st[id].v = a[tl];
        st[id].sz = 1;
        return;
    }
    int tm = (tl+tr)/2;
    build(id*2+1, tl, tm);
    build(id*2+2, tm+1, tr);
    st[id].v = st[id*2+1].v + st[id*2+2].v;
    st[id].sz = tr-tl+1;
}

void push(int id){
    st[id*2+1].tag += st[id].tag;
    st[id*2+2].tag += st[id].tag;
    st[id].v = st[id].rv();
    st[id].tag = 0;
}

void modify(int id, int tl, int tr, int l, int r, int k){
    if(tl == l && tr == r){
        st[id].tag += k;
        return;
    }
    int tm = (tl+tr)/2;
    if(r <= tm) modify(id*2+1, tl, tm, l, r, k);
    else if(l > tm) modify(id*2+2, tm+1, tr, l, r, k);
    else{
        modify(id*2+1, tl, tm, l, tm, k);
        modify(id*2+2, tm+1, tr, tm+1, r, k);
    }
    st[id].v = st[id*2+1].rv() + st[id*2+2].rv();
}

ll query(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) return st[id].rv();

    push(id);
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, tl, tm, l, r);
    if(l > tm) return query(id*2+2, tm+1, tr, l, r);
    return query(id*2+1, tl, tm, l, tm) + query(id*2+2, tm+1, tr, tm+1, r);
}


int main(){
    AC
    int N, Q;

    cin >> N;
    for(int i = 0; i < N; ++i) cin >> a[i];
    build(0, 0, N-1);

    cin >> Q;
    while(Q--){
        int v, x, y, k;
        cin >> v;
        if(v == 1){
            cin >> x >> y >> k;
            modify(0, 0, N-1, x-1, y-1, k);
        } else{
            cin >> x >> y;
            cout << query(0, 0, N-1, x-1, y-1) << endl;
        }
    }
}