/*
 tag: BIT, difficult
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 300008
#define MAXM 300008
typedef long long ll;
int n, m;
int mx[MAXN], mn[MAXN], pos[MAXN];
int bit[MAXN+MAXM];

void add(int x, int v){
    for(; x <= m+n; x += x&-x){
        bit[x] += v;
    }
}

int query(int x){
    int ans = 0;
    for(; x; x -= x&-x){
        ans += bit[x];
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        mn[i] = mx[i] = i;
        pos[i] = m+i;
        add(pos[i], 1);
    }

    int x;
    for(int i = m; i; --i) {
        cin >> x;
        mn[x] = 1; 
        mx[x] = max(mx[x], query(pos[x]));

        add(pos[x], -1);
        pos[x] = i;
        add(pos[x], 1);
    }

    for(int i = 1; i <= n; ++i){
        cout << mn[i] << " " << max(mx[i], query(pos[i])) << endl;
    }
}