#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100003
int a[MAXN];
class Node{
public:
    int v, lv, rv, l, r;
} st[MAXN<<2];

void update(Node& nd, Node& lc, Node& rc, int l, int r){
    nd.l = l; nd.r = r;
    nd.lv = lc.lv + (a[lc.l] == a[lc.r] && a[lc.r] == a[rc.l] ? rc.lv : 0);
    nd.rv = rc.rv + (a[rc.r] == a[rc.l] && a[rc.l] == a[lc.r] ? lc.rv : 0);
    nd.v = max({lc.v, rc.v, a[lc.r] == a[rc.l] ? lc.rv+rc.lv : 0});
}

void build(int id, int tl, int tr){
    if(tl == tr) {
        st[id] = {1, 1, 1, tl, tl};
        return;
    }
    int tm = (tl+tr)/2;
    build(id*2+1, tl, tm);
    build(id*2+2, tm+1, tr);
    update(st[id], st[id*2+1], st[id*2+2], tl, tr);
}

Node query(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) return st[id];
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, tl, tm, l, r);
    if(l > tm) return query(id*2+2, tm+1, tr, l, r);
    Node lc = query(id*2+1, tl, tm, l, tm), rc = query(id*2+2, tm+1, tr, tm+1, r), ans;
    update(ans, lc, rc, l, r);
    return ans;
}

int main(){
    while(1){
        int n, q;
        scanf("%d", &n);
        if(!n) break;
        scanf("%d", &q);

        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        build(0, 0, n-1);
        while(q--){
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(0, 0, n-1, l-1, r-1).v);
        }
    }
    return 0;
}