#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
#define MAXK 103
#define MAXN 103
#define MAXP 1003
#define MAXCOST (MAXP*MAXN)
int dp[MAXN][MAXK], a[MAXK];

int main(){
    for(int i = 0; i < MAXN; ++i) fill(begin(dp[i]), end(dp[i]), MAXCOST);
    dp[0][0] = 0;

    int t;
    scanf("%d", &t);
    while(t--){
        int n, k, ans = MAXCOST;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= k; ++i) scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= k; ++j){
                dp[i][j] = MAXCOST;
                for(int l = 1; l <= k && l <= j; ++l){
                    if(a[l] != -1 && dp[i-1][j-l] != MAXCOST) dp[i][j] = min(dp[i][j], dp[i-1][j-l]+a[l]);
                }
            }
            
            ans = min(ans, dp[i][k]);
        }
        printf("%d\n", ans==MAXCOST ? -1 : ans);
    }
    return 0;
}