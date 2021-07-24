#include <iostream>
using namespace std;

typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

ll sgmt[400002], lz[400002];

void modify(int id, ll v, int l, int r, int tl, int tr){
    sgmt[id] += v*(r-l+1);
    if(l == tl && r == tr) {
        lz[id] += v;
        return;
    }
    int tm = (tl+tr)/2;
    if(r <= tm) modify(id*2+1, v, l, r, tl, tm);
    else if(l > tm) modify(id*2+2, v, l, r, tm+1, tr);
    else{
        modify(id*2+1, v, l, tm, tl, tm);
        modify(id*2+2, v, tm+1, r, tm+1, tr);
    }
}

ll query(int id, ll pre, int l, int r, int tl, int tr){
    if(l == tl && r == tr) return pre*(r-l+1) + sgmt[id];
    pre+=lz[id];
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, pre, l, r, tl ,tm);
    if(l > tm) return query(id*2+2, pre, l, r, tm+1, tr);
    return query(id*2+1, pre, l, tm, tl, tm)+query(id*2+2, pre, tm+1, r, tm+1, tr);
}

int main(){
    AC
    int t, n, c, x, p, q, v;
    cin >> t;
    while(t--){
        cin >> n >> c;
        while(c--){
            cin >> x >> p >> q;
            --p; --q;
            if(!x) {
                cin >> v;
                modify(0, v, p, q, 0, n-1);
            } else {
                cout << query(0, 0, p, q, 0, n-1) << endl; 
            }
        }
        fill(begin(sgmt), end(sgmt), 0);
        fill(begin(lz), end(lz), 0);
    }
    return 0;
}