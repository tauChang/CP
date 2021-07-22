#include <iostream>
#include <unordered_map>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
 
unordered_map<ll, ll> map;
 
ll dp(ll n){
    if(n < 12) return n;
    if(map.find(n) != map.end()) return map[n];
    return map[n] = max(n, dp(n/2)+dp(n/3)+dp(n/4));
}
 
int main(){
    AC
    ll n;
    while(cin >> n){
        cout << dp(n) << endl;
        map.clear();
    }
    return 0;
} 
