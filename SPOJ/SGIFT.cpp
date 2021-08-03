#include <iostream>
#include <algorithm>
#include <vector>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;

int main(){
    AC
    int n, q;
    cin >> n;
    vector<int> arr(n+1, 0);
    vector<ll> pre(n+1, 0);
    for(int i = 1, x; i <= n; ++i) cin >> arr[i];
    sort(begin(arr), end(arr));
    for(int i = 1; i <= n; ++i) pre[i] = arr[i] + pre[i-1];

    cin >> q;
    while(q--){
        int l, r, lb, ub;
        cin >> l >> r;
        lb = lower_bound(begin(arr), end(arr), l)-begin(arr)-1;
        ub = upper_bound(begin(arr), end(arr), r)-begin(arr)-1;
        cout << pre[ub]-pre[lb] << endl;
    }
    return 0;
}