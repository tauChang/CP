#include <iostream>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
typedef long long ll;

ll v[2002];
ll dp[2002][2002];

int main(){
    AC
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        dp[i][i] = v[i]*n;
    }
    for(int cnt = 2; cnt <= n; cnt++){
        int age = n-cnt+1;
        for(int i = 0; i+cnt-1 <= n; i++){
            int j = i+cnt-1;
            dp[i][j] = max(v[i]*age+dp[i+1][j], v[j]*age+dp[i][j-1]);
        }
    }

    cout << dp[0][n-1];
}