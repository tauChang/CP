#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
typedef long long ll;

int main(){
    AC
    ll n;
    while(cin >> n){
        string T, S;
        cin >> T >> S;
        vector<ll> pre(n);
        pre[0] = -1;
        for(ll i = 1, j = -1; i < n; ++i){
            while(j >= 0 && T[j+1] != T[i]) j = pre[j];
            if(T[j+1] == T[i]) ++j;
            pre[i] = j;
        }
        ll cnt = 0;
        for(ll i = 0, j=-1; i < S.size(); ++i){
            while(j >= 0 && T[j+1] != S[i]) j = pre[j];
            if(T[j+1] == S[i]) ++j;
            if(j == n-1) {
                ++cnt;
                cout << i-j << endl;
                j = pre[j];
            }
        }
        if(!cnt) cout << endl;
    }
    return 0;
}