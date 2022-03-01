/*
 tag: BIT, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 100005
#define F first
#define S second
typedef long long ll;
int bit[MAXN], b[MAXN], n;
pair<int, int> a[MAXN];

void add(int x){
    for(; x <= MAXN; x += x&-x) bit[x]++;
}

int query(int x){
    int ans = 0;
    for(; x; x-= x&-x) ans += bit[x];
    return ans;
}

int main(){
    int c = 1;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].F);
            a[i].S = i;
        }
        sort(begin(a)+1, begin(a)+n+1);
        for(int i = 1; i <= n; ++i){
            b[a[i].S] = i;
        }
        ll cnt = 0;
        for(int i = 1; i <= n; ++i){
            add(b[i]);
            cnt += i - query(b[i]);
        }
        printf("Case #%d: %lld\n", c++, cnt);
    }

}