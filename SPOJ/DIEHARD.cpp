#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
int memo[1010][1500][3];

int dp(int h, int a, int p){
    if(h <= 0 || a <= 0) return 0;
    if(memo[h][a][p] != -1) return memo[h][a][p];
    int fire = p == 0 ? -1 : dp(h+3, a+2, 0)+1;
    int water = p == 1 ? -1 : dp(h-5, a-10, 1)+1;
    int air = p == 2 ? -1 : dp(h-20, a+5, 2)+1;
    return memo[h][a][p] = max({fire, water, air});
}

int main(){
    AC 
    memset(memo, -1, sizeof(memo));
    int t, a, h;
    cin >> t;
    while(t--){
        cin >> h >> a;
        cout << max({dp(h+3, a+2, 0), dp(h-5, a-10, 1), dp(h-20, a+5, 2)}) << endl;
    }
}