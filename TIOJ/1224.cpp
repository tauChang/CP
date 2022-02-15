/*
 tag: segment tree, difficult
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXX 1000005
typedef long long ll;
int st[MAXX << 2], tag[MAXX << 2]; // st: non-zero instances in this range

void modify(int id, int tl, int tr, int l, int r, int v){
    if(tl == l && tr == r) {
        tag[id] += v;
    } else{
        int tm = (tl + tr)/2;
        if(r <= tm) modify(id*2+1, tl, tm, l, r, v);
        else if(l > tm) modify(id*2+2, tm+1, tr, l, r, v);
        else{
            modify(id*2+1, tl, tm, l, tm, v);
            modify(id*2+2, tm+1, tr, tm+1, r, v);
        }
    }

    if(tag[id]) st[id] = tr-tl+1;
    else if(tl == tr) st[id] = 0;
    else st[id] = st[id*2+1] + st[id*2+2];
}

int main(){
    AC
    int n;
    vector<tuple<int, int, int, int>> a;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        a.push_back({d, l, r-1, 1});
        a.push_back({u, l, r-1, -1});
    }
    sort(a.begin(), a.end());

    int preY = 0;
    ll area = 0;
    for(auto& [y, l, r, v]:a){
        area += 1LL * st[0] * (y - preY);
        modify(0, 0, MAXX, l, r, v);
        preY = y;
    }
    cout << area;
    return 0;
}