/*
 tag: BIT, 2D-BIT, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXN 1028
typedef long long ll;
ll bit[MAXN][MAXN];
int n;

void add(int xx, int yy, int z){
    for(int x = xx; x <= n; x += x&-x){
        for(int y = yy; y <= n; y+= y&-y){
            bit[x][y] += z;
        }
    }
}

ll query(int xx, int yy){
    ll ans = 0;
    for(int x = xx; x; x -= x&-x){
        for(int y = yy; y; y -= y&-y){
            ans += bit[x][y];
        }
    }
    return ans;
}


int main(){
    AC
    cin >> n;
    int t, a, b, c, d;
    while(cin >> t){
        if(t == 1) {
            cin >> a >> b >> c;
            ++a; ++b;
            add(a, b, c);
        } else{
            cin >> a >> b >> c >> d;
            ++a; ++b; ++c; ++d;
            cout << query(c, d) - query(c, b-1) - query(a-1, d) + query(a-1, b-1) << endl;
        }
    }
}