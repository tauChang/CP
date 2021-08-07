#include <iostream>
#include <algorithm>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define MAXN 50002

class Node{
public:
    int v;
    int sv;
    int ev;
    int sum;
} seg[MAXN*4];

int a[MAXN], n;

void update(Node& nd, Node lc, Node rc){
    nd.sum = lc.sum + rc.sum;
    nd.sv = max(lc.sv, lc.sum+rc.sv);
    nd.ev = max(rc.ev, lc.ev+rc.sum);
    nd.v = max({lc.v, rc.v, lc.ev+rc.sv});
}

void init(int id, int tl, int tr){
    if(tl == tr) {
        seg[id] = {a[tl], a[tl], a[tl], a[tl]};
        return;
    }
    int tm = (tl+tr)/2;
    init(id*2+1, tl, tm);
    init(id*2+2, tm+1, tr);
    update(seg[id], seg[id*2+1], seg[id*2+2]);
}

Node query(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) return seg[id];
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, tl, tm, l, r);
    if(l > tm) return query(id*2+2, tm+1, tr, l, r);
    Node lc = query(id*2+1, tl, tm, l, tm), rc = query(id*2+2, tm+1, tr, tm+1, r);
    Node ans;
    update(ans, lc, rc);
    return ans;
}

void modify(int id, int tl, int tr, int x, int v){
    if(tl == x && tr == x) {
        seg[id] = {v, v, v, v};
        return;
    }
    int tm = (tl+tr)/2;
    if(x <= tm) modify(id*2+1, tl, tm, x, v);
    else if(x > tm) modify(id*2+2, tm+1, tr, x, v);
    update(seg[id], seg[id*2+1], seg[id*2+2]);
}

int main(){
    AC
    int m;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    init(0, 0, n-1);
    cin >> m;
    while(m--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t) cout << query(0, 0, n-1, x-1, y-1).v << endl;
        else modify(0, 0, n-1, x-1, y);
    }

    return 0;
}