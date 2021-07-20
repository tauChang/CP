#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll, ll> tll;
int n;
ll a[50002], v[200002], lv[200002], rv[200002], sum[200002];

void build(int id, int tl, int tr){
    if(tl == tr) {
        v[id] = lv[id] = rv[id] = sum[id] = a[tl];
        return;
    }

    int tm = (tl+tr)/2;
    build(id*2+1, tl, tm);
    build(id*2+2, tm+1, tr);
    v[id] = max({v[id*2+1], v[id*2+2], rv[id*2+1]+lv[id*2+2]});
    lv[id] = max(lv[id*2+1], sum[id*2+1]+lv[id*2+2]);
    rv[id] = max(rv[id*2+2], rv[id*2+1]+sum[id*2+2]);
    sum[id] = sum[id*2+1] + sum[id*2+2];
}

tll query(int id, int l, int r, int tl, int tr){
    if(l == tl && r == tr) return {v[id], lv[id], rv[id], sum[id]};
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, l, r, tl, tm);
    if(l > tm) return query(id*2+2, l, r, tm+1, tr);
    tll left = query(id*2+1, l, tm, tl, tm), right = query(id*2+2, tm+1, r, tm+1, tr);
    return {
        max({get<0>(left), get<0>(right), get<2>(left)+get<1>(right)}),
        max(get<1>(left), get<3>(left)+get<1>(right)),
        max(get<2>(right), get<2>(left)+get<3>(right)),
        get<3>(left)+get<3>(right)
    };
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    build(0, 0, n-1);

    int m, l, r;
    cin >> m;
    while(m--){
        cin >> l >> r;
        cout << get<0>(query(0, l-1, r-1, 0, n-1)) << endl;
    }
}