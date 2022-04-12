/*
 tag: deque, sliding window, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
#include <deque>
using namespace std;
typedef long long ll;
#define F first
#define S second

int main(){
    int n, m;
    ll k, h;
    deque<pair<int, ll>> mn, mx;
    vector<pair<int, int>> ans;

    scanf("%d %d %lld", &n, &m, &k);
    m = min(m, n);
    for(int i = 1; i <= n+m-1; ++i){
        if(!mn.empty() && mn.front().F < i-m+1) mn.pop_front();
        if(!mx.empty() && mx.front().F < i-m+1) mx.pop_front();
        
        if(i <= n){
            scanf("%lld", &h);
            while(!mn.empty() && mn.back().S > h) mn.pop_back();
            while(!mx.empty() && mx.back().S < h) mx.pop_back();
            mn.push_back({i, h});
            mx.push_back({i, h});
        }

        if(mx.front().S - mn.front().S == k) ans.push_back({max(1, i-m+1), min(i, n)});
    }

    printf("%d\n", ans.size());
    for(auto& p:ans) printf("%d %d\n", p.F, p.S);

    return 0;
}