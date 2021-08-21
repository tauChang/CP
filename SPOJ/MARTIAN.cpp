#include <iostream>
using namespace std;
#define MAXM 500
#define MAXN 500
int dp[MAXM][MAXN][2], yy[MAXM][MAXN], bg[MAXM][MAXN];

int main(){
    int m, n;
    while(1){
        scanf("%d %d", &m, &n);
        if(!m) break;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1, v; j <= n; ++j) {
                scanf("%d", &v);
                yy[i][j] = yy[i][j-1] + v;
            }
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 1, v; j <= n; ++j) {
                scanf("%d", &v);
                bg[i][j] = bg[i-1][j] + v;
            }
        }

        for(int l = 1; l <= m+n-1; ++l){
            int i = min(l, m), j = l-i+1;
            while(i >= 1 && j <= n){
                dp[i][j][0] = yy[i][j] + max(dp[i-1][j][0], dp[i-1][j][1]);
                dp[i][j][1] = bg[i][j] + max(dp[i][j-1][0], dp[i][j-1][1]);
                --i; ++j;
            }
        }
        printf("%d\n", max(dp[m][n][0], dp[m][n][1]));
    }
    return 0;
}
