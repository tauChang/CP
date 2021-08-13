#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int a[100004];
vector<int> st[400009];

void build(int id, int tl, int tr){
    if(tl == tr) {
        st[id].push_back(a[tl]);
        return;
    }
    int tm = (tl+tr)/2;
    build(id*2+1, tl, tm);
    build(id*2+2, tm+1, tr);
    int i = 0, j = 0;
    vector<int>& lc = st[id*2+1], rc = st[id*2+2];
    while(i < lc.size() || j < rc.size()){
        if(i == lc.size() || (j < rc.size() && rc[j] <= lc[i])) st[id].push_back(rc[j++]);
        else st[id].push_back(lc[i++]);
    }
}

int query(int id, int tl, int tr, int l, int r, int x){
    if(tl == l && tr == r) return upper_bound(st[id].begin(), st[id].end(), x) - st[id].begin();
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, tl, tm, l, r, x);
    else if(l > tm) return query(id*2+2, tm+1, tr, l, r, x);
    else return query(id*2+1, tl, tm, l, tm, x)+query(id*2+2, tm+1, tr, tm+1, r, x);
}

int main(){
    AC
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n ;++i) cin >> a[i];
    build(0, 0, n-1);
    sort(a, a+n);

    while(q--){
        int l, r, k, b = 0, e = n-1, m;
        cin >> l >> r >> k;
        --l; --r; 
        while(b < e){
            m = (b+e+1)/2;
            if(query(0, 0, n-1, l, r, a[m]-1) <= k-1) b = m;
            else e = m-1;
        }
        cout << a[b]<< endl;
    }
    return 0;
}