#include <iostream>
using namespace std;
#define MAXBUDGET 504
#define MAXN 104
 
int main(){
    int bj, n;
    int dp[MAXN][MAXBUDGET], c[MAXN], f[MAXN];
    while(1){
        scanf("%d %d", &bj, &n);
        if(!bj && !n) break;
 
        for(int i = 1; i <= n; ++i) scanf("%d %d", &c[i], &f[i]);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= bj; ++j){
                if(c[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], f[i]+dp[i-1][j-c[i]]);
            }
        }
        int cost = 0;
        for(;;cost++) if(dp[n][cost] == dp[n][bj]) break;
        printf("%d %d\n", cost, dp[n][bj]);
 
    }
    return 0;
}
 