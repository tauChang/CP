/*
 tag: segment tree, persistent, difficult
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 100005
#define MAXM 5005
struct Node{
    int lc, rc, cnt;
    Node() {
        lc = rc = cnt = 0;
    }
} st[MAXN * 20];

int n, m, roots[MAXN], cur = 1;
vector<int> a, b;

void update(int& id, int preId, int tl, int tr, int x){
    id = cur++;
    st[id] = st[preId];
    st[id].cnt++;
    if(tl == tr) return;
    int tm = (tl+tr)/2;
    if(x <= tm) update(st[id].lc, st[preId].lc, tl, tm, x);
    else update(st[id].rc, st[preId].rc, tm+1, tr, x);
}

int query(int id1, int id2, int tl, int tr, int k){
    if(tl == tr) return tl;
    int tm = (tl+tr)/2, lcnt = st[st[id2].lc].cnt - st[st[id1].lc].cnt;
    if(k <= lcnt) return query(st[id1].lc, st[id2].lc, tl, tm, k);
    else return query(st[id1].rc, st[id2].rc, tm+1, tr, k-lcnt);
}


int main(){
    AC
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 0; i < n; ++i){
        update(roots[i+1], roots[i], 0, b.size()-1, lower_bound(b.begin(), b.end(), a[i])-b.begin());
    }

    int l, r, k;
    while(m--){
        cin >> l >> r >> k;
        cout << b[query(roots[l-1], roots[r], 0, b.size()-1, k)] << endl;
    }
}