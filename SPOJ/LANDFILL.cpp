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
#define MAXV 1000000
#define MAXN 102
#define F first
#define S second

struct Node{
    int val;
    int st[MAXN << 2];
    int tag[MAXN << 2];
};

Node dp[2][MAXV];
int n, v, k, h[MAXN], e[MAXN], c[MAXN];

void push(int st[], int tag[], int id){
    tag[id*2+1] += tag[id];
    tag[id*2+2] += tag[id];
    st[id] += tag[id];
    tag[id] = 0;
}

void build(int st[], int id, int tl, int tr){
    if(tl == tr) {
        st[id] = h[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(st, id*2+1, tl, tm);
    build(st, id*2+2, tm+1, tr);
    st[id] = min(st[id*2+1], st[id*2+2]);
}

void add(int st[], int tag[], int id, int tl, int tr, int l, int r, int x){
    if(tl == l && tr == r) {
        tag[id] += x;
        return;
    }

    int tm = (tl + tr) / 2;
    if(r <= tm) add(st, tag, id*2+1, tl, tm, l, r, x);
    else if (l > tm) add(st, tag, id*2+2, tm+1, tr, l, r, x);
    else {
        add(st, tag, id*2+1, tl, tm, l, tm, x);
        add(st, tag, id*2+2, tm+1, tr, tm+1, r, x);
    }
    st[id] = min(st[id*2+1]+tag[id*2+1], st[id*2+2]+tag[id*2+2]);
}

// int query(int st[], int tag[], int id, int tl, int tr, int l, int r){ if(tl == l && tr == r) return st[id]+tag[id]; push(st, tag, id); int tm = (tl + tr) / 2; if(r <= tm) return query(st, tag, id*2+1, tl, tm, l, r); if(l > tm) return query(st, tag, id*2+2, tm+1, tr, l, r); return min(query(st, tag, id*2+1, tl, tm, l, tm), query(st, tag, id*2+2, tm+1, tr, tm+1, r));
// }

Node operation(Node nd, int i, int k){
    add(nd.st, nd.tag, 0, 1, n, i, i+k-1, e[i]);
    nd.val = nd.st[0] + nd.tag[0];
    return nd;
}

int main(){
    AC
    cout << "HEY";
    cin >> n >> v >> k;
    for(int i = 1; i <= n; ++i){
        cin >> h[i] >> e[i] >> c[i];
    }

    build(dp[0][0].st, 0, 1, n);
    for(int j = 1; j <= v; ++j) dp[0][j] = dp[0][0];

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= v; ++j){
            cout << "HEY";
            Node nd;
            if(c[i] <= j) nd = operation(dp[0][j-c[i]], i, k);

            if(c[i] <= j && nd.val >= dp[0][j].val){
                dp[1][j] = nd;
            } else{
                dp[1][j] = dp[0][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        swap(dp[0], dp[1]);
    }

    cout << dp[0][v].val;
}