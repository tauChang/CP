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
#define MAXN 10003
#define MAXX 1003
#define MAXY 1003
int n, bit[MAXX][MAXY], pts[MAXN][2];

void add(int xx, int yy){
    for(int x = xx; x < MAXX; x += (x&-x)){
        for(int y = yy; y < MAXY; y += (y&-y)){
            bit[x][y]++;
        }
    }
}

int query(int xx, int yy){
    int ans = 0;
    for(int x = xx; x; x -= (x&-x)){
        for(int y = yy; y; y -= (y&-y)){
            ans += bit[x][y];
        }
    }
    return ans;
}

int main(){
    AC
    while(cin >> n){
        memset(bit, 0, sizeof(bit));
        for(int i = 0; i < n; ++i) {
            cin >> pts[i][0] >> pts[i][1];
            add(pts[i][0], pts[i][1]);
        }
        for(int i = 0; i < n; ++i){
            cout << query(pts[i][0]-1, pts[i][1]-1) << endl;
        }
    }

}