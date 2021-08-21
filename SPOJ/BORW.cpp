#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 204
#define MAXX 1000004
int memo[MAXN][MAXN][MAXN];
int a[MAXN], n;

int dp(int i, int inc, int dec){
    if(i > n) return 0;
    if(memo[i][inc][dec] != -1) return memo[i][inc][dec];

    int ans = 0;
    if(a[i] > a[inc]) ans = max(ans, 1+dp(i+1, i, dec));
    if(a[i] < a[dec]) ans = max(ans, 1+dp(i+1, inc, i));
    ans = max(ans, dp(i+1, inc, dec));
    return memo[i][inc][dec] = ans;
}

int main(){
    a[0] = 0; a[MAXN-1] = MAXX;
    while(1){
        memset(memo, -1, sizeof(memo));
        scanf("%d", &n);
        if(n == -1) break;
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        printf("%d\n", n-dp(1, 0, MAXN-1));
    }
    return 0;
}