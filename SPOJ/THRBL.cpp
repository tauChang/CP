/*
 tag: RMQ
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 50002
#define MAXJ 20
int h[MAXN], st[MAXN][MAXJ];

void build(int n){
    for(int i = 0; i < n; ++i) st[i][0] = h[i];
    for(int j = 1; j < MAXJ; ++j){
        for(int i = 0; i+(1<<j) <= n; ++i){
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int a, int b){
    int j = 31 - __builtin_clz(b-a);
    return max(st[a][j], st[b-(1<<j)][j]);
}

int main(){
    AC
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> h[i];
    build(n);
    int count = 0;
    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(a > b) swap(a, b);
        if(a == b || a+1 == b) count++;
        else count += (rmq(a+1, b) <= h[a]);
    }
    cout << count;
}