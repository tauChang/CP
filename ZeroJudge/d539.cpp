/*
 tag: RMQ, sparse table, segment tree
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define MAXN 500002
#define MAXJ 25
using namespace std;

int st[MAXN][MAXJ];
void build(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n; ++i) st[i][0] = a[i];
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 0; i+(1<<j)-1 < n; ++i){
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int x, int y){
    int j = floor(log2(y-x+1));
    return max(st[x][j], st[y-(1<<j)+1][j]);
}

int main(){
    AC
    int n, q;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    build(a);
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        --x; --y;
        if(y < x) swap(x, y);
        cout << rmq(x, y) << endl;
    }
}