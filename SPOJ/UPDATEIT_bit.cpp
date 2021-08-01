#include <iostream>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int bit[40005];

void add(int i, int v, int n){
    for(; i <= n; i += (i & -i)) bit[i] += v;
}

int query(int i, int n){
    int ans = 0;
    for(; i > 0; i -= (i & -i)) ans += bit[i];
    return ans;
}

int main(){
    AC
    int t;
    cin >> t;
    while(t--){
        int n, u, q;
        cin >> n >> u;
        fill(begin(bit), begin(bit)+n+2, 0);
        while(u--){
            int l, r, v;
            cin >> l >> r >> v;
            add(l+1, v, n);
            add(r+2, -v, n);
        }
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            cout << query(x+1, n) << endl;
        }
    }
    return 0;
}