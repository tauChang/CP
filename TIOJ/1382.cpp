
/*
 tag: segment tree, cyclic pattern, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 100010
int st[MAXN << 2], n;

void build(int id, int tl, int tr){
    if(tl == tr) {
        st[id] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(id*2+1, tl, tm);
    build(id*2+2, tm+1, tr);
    st[id] = st[id*2+1] + st[id*2+2];
}

int query(int id, int tl, int tr, int k){
    if(tl == tr) {
        st[id] = 0;
        return tl;
    }
    int tm = (tl + tr) / 2, ans;
    if(k <= st[id*2+1]) ans = query(id*2+1, tl, tm, k);
    else ans = query(id*2+2, tm+1, tr, k - st[id*2+1]);
    st[id] = st[id*2+1] + st[id*2+2];
    return ans;
}

int main(){
    AC
    while(cin >> n){
        build(0, 0, n-1);

        int cur = 0, a;
        for(int i = 0; i < n; ++i){
            cin >> a;
            cur = (cur + a - 1) % (n-i);
            cout << query(0, 0, n-1, cur+1) + 1;
            if(i+1 != n) {
                cur %= (n-i-1);
                cout << " ";
            }
        }
        cout << endl;
    }
}