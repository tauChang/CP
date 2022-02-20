/*
 tag: RMQ, easy
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 1000005
int h[MAXN], st[MAXN << 2];

void build(int id, int tl, int tr){
    if(tl == tr) {
        st[id] = h[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(id*2+1, tl, tm);
    build(id*2+2, tm+1, tr);
    st[id] = min(st[id*2+1], st[id*2+2]);
}

int query(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) return st[id];
    int tm = (tl + tr) / 2;
    if(r <= tm) return query(id*2+1, tl, tm, l, r);
    if(l > tm) return query(id*2+2, tm+1, tr, l, r);

    return min(query(id*2+1, tl, tm, l, tm), query(id*2+2, tm+1, tr, tm+1, r));
}

int main(){
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> h[i];
    build(0, 0, n-1);
    while(cin >> a >> b){
        cout << query(0, 0, n-1, a-1, b-1) + 1<< endl;
    }
}