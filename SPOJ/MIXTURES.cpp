#include <iostream>
#include <climits>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int a[102], pre[102], dp[102][102];
int main(){
    AC
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
            dp[i][i] = 0;
        }
        for(int l = 2; l <= n; ++l){
            for(int i = 1; i+l-1 <= n; ++i){
                int j = i+l-1;
                dp[i][j] = INT_MAX; // max = 99 * 99 * 99
                for(int k = i; k < j; ++k){
                    int s1 = (pre[k]-pre[i-1])%100, s2 = (pre[j]-pre[k])%100;
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+s1*s2);
                }
            }
        }

        cout << dp[1][n] << endl;
    }
}
