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
typedef unsigned long long ull;
#define MAXN 100010
int n, bit[MAXN];
ull s[MAXN], ss[MAXN];

int query(int x){
    int ans = 0;
    for(; x; x -= (x&-x)){
        ans += bit[x];
    }
    return ans;
}

void update(int x){
    for(; x <= n; x += (x&-x)){
        bit[x]++;
    }
}

int main(){
    AC
    while(cin >> n){
        memset(bit, 0, sizeof(bit));
        for(int i = 0; i < n; ++i){
            cin >> s[i];
            ss[i] = s[i];
        }
        sort(begin(ss), begin(ss)+n);
        for(int i = 0; i < n; ++i){
            int id = lower_bound(begin(ss), begin(ss)+n, s[i]) - begin(ss) + 1;
            cout << i+1-query(id) << "\n";
            update(id);
        }
    }
}