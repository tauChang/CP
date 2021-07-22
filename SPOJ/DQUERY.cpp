#include <iostream>
#include <algorithm>
#include <math.h>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

class query{
public:
    int l;
    int r;
    int i;
};

int a[30002], ans[200002], map[1000002];
int n, q, k;
query qs[200002];

bool cmp(query& q1, query& q2){
    int b1 = q1.l/k, b2 = q2.l/k;
    if(b1 < b2 || (b1 == b2 && q1.r < q2.r)) return true;
    return false;
}

int main(){
    AC
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].l--; qs[i].r--;
        qs[i].i = i;
    }
    k = n/sqrt(q);
    sort(qs, qs + q, cmp);
    int L = 0, R = 0, uq = 1;
    map[a[L]] = 1;
    for(int i = 0; i < q; ++i){
        int l = qs[i].l, r = qs[i].r;
        while(l < L) uq += (map[a[--L]]++ == 0);
        while(r > R) uq += (map[a[++R]]++ == 0);
        while(l > L) uq -= (map[a[L++]]-- == 1);
        while(r < R) uq -= (map[a[R--]]-- == 1);

        ans[qs[i].i] = uq;
    }

    for(int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}