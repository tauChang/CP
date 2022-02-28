/*
 tag: BIT, RMQ, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 100005
typedef long long ll;
ll a[MAXN], d[MAXN], di[MAXN];
int n, q;

void add(ll bit[], int x, ll v){
    for(; x <= MAXN; x += x&-x) bit[x] += v;
}

ll query(ll bit[], int x){
    ll ans = 0;
    for(; x; x -= x&-x) ans += bit[x];
    return ans;
}

ll qry(int x){
    return (x+1)*query(d, x)-query(di, x);
}

int main(){
    AC
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        add(d, i, a[i]-a[i-1]);
        add(di, i, (a[i]-a[i-1])*i);
    }

    char t;
    int l, r;
    ll v;
    while(q--){
        cin >> t;
        if(t == 'Q') {
            cin >> l >> r;
            cout << qry(r) - qry(l-1) << endl;
        } else{
            cin >> l >> r >> v;
            add(d, l, v); add(di, l, v*l);
            add(d, r+1, -v); add(di, r+1, -v*(r+1));
        }
    }
}