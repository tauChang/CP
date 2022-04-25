/*
 tag: huffman tree, difficult
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
    int n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    scanf("%d", &n);
    for(int i = 0, x; i < n; ++i) {
        scanf("%d", &x);
        pq.push(x);
    }
    ll ans = 0;
    while(pq.size() > 1){
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();
        ans += x+y;
        pq.push(x+y);
    }
    printf("%lld", ans);
}