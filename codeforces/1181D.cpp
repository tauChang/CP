/*
 tag: segment tree, difficult
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
#define MAXN 500005
#define MAXM 500005
#define MAXQ 500005
#define F first
#define S second
pair<ll, int> st[MAXN << 2];
int ans[MAXQ];
ll cnt[MAXM];
pair<ll, int> v[MAXM];
pair<ll, int> k[MAXQ];
int n, m, q;

void add(int id, int tl, int tr, int x){
    if(tl == tr) {
        st[id] = {1, x};
        return;
    }
    int tm = (tl+tr)/2;
    if(x <= tm) add(id*2+1, tl, tm, x);
    else if(x > tm) add(id*2+2, tm+1, tr, x);
    st[id].F = st[id*2+1].F + st[id*2+2].F;
}

int query(int id, int tl, int tr, int k){
    if(tl == tr) return st[id].S;
    int tm = (tl+tr)/2;
    if(k <= st[id*2+1].F) return query(id*2+1, tl, tm, k);
    return query(id*2+2, tm+1, tr, k-st[id*2+1].F);
}

void solve(){
    int vi = 0, qi = 0;
    ll start = n+1, end = -1;

    while(qi < q){
        ll x = v[vi].F;
        while(vi < m && v[vi].F == x){
            add(0, 0, m-1, v[vi].S);
            ++vi;
        }
        if(vi < m) end = start + (v[vi].F - x)*vi;
        else end = LLONG_MAX;

        while(qi < q && k[qi].F < end){
            ans[k[qi].S] = query(0, 0, m-1, (k[qi].F - start) % vi + 1);
            ++qi;
        }
        start = end;
    }
}

int main(){
    AC
    cin >> n >> m >> q;
    for(int i = 0, x; i < n; ++i) {
        cin >> x;
        cnt[x-1]++;
    }

    for(int i = 0; i < m; ++i){
        v[i] = {cnt[i], i};
    }
    sort(begin(v), begin(v)+m);
    
    for(int i = 0; i < q; ++i){
        cin >> k[i].F;
        k[i].S = i;
    }
    sort(begin(k), begin(k)+q);
    solve();

    for(int i = 0; i < q; ++i) cout << ans[i]+1 << "\n";
}
