#include <iostream>
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define MAXN 20
using namespace std;
typedef long long ll;

int main(){
    AC
    int t, n;
    bool M[MAXN][MAXN];
    ll dp[1 << MAXN]; 

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) cin >> M[i][j];

        for(int mask = 1; mask < (1<<n); ++mask){
            int i = -1;
            for(int j = 0; j < n; ++j) i += (mask&(1<<j)) != 0;

            if(!i) {
                int j = 0;
                for(;; j++) if(mask&(1 << j)) break;
                dp[mask] = M[i][j];
                continue;
            }
            dp[mask] = 0;

            for(int j = 0; j < n; ++j) {
                if((mask & (1<<j)) && M[i][j])
                    dp[mask] += dp[mask & ~(1<<j)];
            }
        }
        cout << dp[(1<<n)-1] << endl;
    }
    return 0;
}