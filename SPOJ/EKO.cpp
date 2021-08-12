#include <iostream>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
typedef long long ll;

int n, t, a[1000003];

bool sat(int x){
    ll sum = 0;
    for(int i = 0; i < n && sum < t; ++i) if(a[i] > x) sum += a[i]-x;
    return sum >= t;
}

int main(){ 
    AC
    cin >> n >> t;
    int l = 1, r = -1, m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    while(l < r){
        m = (l+r+1)/2;
        if(!sat(m)) r = m-1;
        else l = m;
    }
    cout << l;
    return 0;
}