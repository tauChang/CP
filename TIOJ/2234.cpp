/*
 tag: math, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define F first
#define S second
typedef pair<double, double> pdd;
typedef long long ll;
vector<pdd> arr;

ll count(){
    sort(begin(arr), end(arr));

    double prex = arr[0].F;
    ll cnt = 1, ans = 0;
    for(int i = 1; i < arr.size(); ++i){
        if(arr[i].F == prex) cnt++;
        else {
            ans += cnt-1;
            prex = arr[i].F;
            cnt = 1;
        }
    }
    ans += cnt-1;
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    arr.resize(n);
    for(int i = 0; i < n; ++i) scanf("%lf %lf", &arr[i].F, &arr[i].S);
    ll ans = 0;
    // vertical
    ans += count();

    // horizontal
    for(auto& p:arr) swap(p.F, p.S);
    ans += count();
    
    // right diagonal
    for(auto& p:arr) {
        swap(p.F, p.S);
        p = {p.F/2-p.S/2, p.F/2+p.S/2};
    }
    ans += count();
    
    // left diagonal
    for(auto&p:arr) swap(p.F, p.S);
    ans += count();
    
    printf("%lld", ans);
    return 0;
}