#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 1003
int a[MAXN], dp[MAXN][2];


int main(){
    int n, g = 0;
    while(1){
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int x = 0;
        for(int l = 2; l <= n; l+=2){
            x=1-x;
            for(int i = 0; i+l-1 < n; ++i){
                int j = i+l-1;
                int left = a[i] + (a[i+1] >= a[j] ? dp[i+2][1-x]-a[i+1] : dp[i+1][1-x]-a[j]);
                int right = a[j] + (a[i] >= a[j-1] ? dp[i+1][1-x]-a[i] : dp[i][1-x]-a[j-1]);
                dp[i][x] = max(left, right);
            }
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ++g, dp[0][x]);
    }
    return 0;
}