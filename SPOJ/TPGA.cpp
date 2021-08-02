#include <iostream>
using namespace std;

typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int BIT[200005];

void increment(int n, int i){
    for(; i <= n; i += (i & -i)) BIT[i] += 1;
}

int query(int n, int i){
    int ans = 0;
    for(; i > 0; i -= (i & -i)) ans += BIT[i];
    return ans;
}

int main(){
    AC
    int t, n, a[200005];
    ll fac[200005], m = 1000000007;

    fac[0] = 1;
    for(int i = 1; i <= 200000; ++i) fac[i] = (fac[i-1] * i) % m;

    cin >> t;
    while(t--){
        cin >> n;
        fill(begin(BIT), begin(BIT)+n+1, 0);
        for(int i = 0; i < n; ++i) cin >> a[i];
        ll ans = 1;
        for(int i = 0; i < n; ++i) {
            ans += (a[i]-query(n, a[i])-1) * fac[n-i-1];
            increment(n, a[i]);
        }
        cout << ans%m << endl;
    }
}