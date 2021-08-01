#include <iostream>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int T[40005];

void modify(int v, int id, int l, int r, int tl, int tr){
    if(l == tl && r == tr) {
        T[id] += v;
        return;
    }
    int tm = (tl+tr)/2;
    if(r <= tm) modify(v, id*2+1, l, r, tl, tm);
    else if(l > tm) modify(v, id*2+2, l, r, tm+1, tr);
    else{
        modify(v, id*2+1, l, tm, tl, tm);
        modify(v, id*2+2, tm+1, r, tm+1, tr);
    }
}

int query(int id, int x, int tl, int tr){
    if(x == tl && x == tr) return T[id];
    int tm = (tl+tr)/2;
    if(x <= tm) return T[id] + query(id*2+1, x, tl, tm);
    return T[id] + query(id*2+2, x, tm+1, tr);
}

int main(){
    AC
    int t;
    cin >> t;
    while(t--){
        int n, u, q;
        cin >> n >> u;
        fill(begin(T), begin(T)+n*4, 0);
        while(u--){
            int l, r, v;
            cin >> l >> r >> v;
            modify(v, 0, l, r, 0, n-1);
        }
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            cout << query(0, x, 0, n-1) << endl;
        }
    }
    return 0;
}