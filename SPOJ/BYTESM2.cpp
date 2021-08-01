#include <iostream>
#include <algorithm>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main(){
	AC
    int n;
    cin >> n;
    while(n--){
        int r, c, dp[102][102] = {0}, M[102][102] = {0};
        cin >> r >> c;
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; ++j) cin >> M[i][j];
        }
        for(int i = r; i >= 1; i--){
            for(int j = 1; j <= c; ++j) dp[i][j] = M[i][j] + max({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
        }
        cout << *max_element(begin(dp[1]), end(dp[1])) << endl;
    }
    return 0;
}