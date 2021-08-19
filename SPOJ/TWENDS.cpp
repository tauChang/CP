#include <iostream>
using namespace std;
#define MAXN 1003
int a[MAXN], dp[MAXN][MAXN];


int main(){
    int n, g = 0;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for(int l = 2; l <= n; ++l){
            for(int i = 0; i+l-1 < n; ++i){
                int j = i+l-1;
                int left = a[i] + (a[i+1] >= a[j] ? dp[i+2][j]-a[i+1] : dp[i+1][j-1]-a[j]);
                int right = a[j] + (a[i] >= a[j-1] ? dp[i+1][j-1]-a[i] : dp[i][j-2]-a[j-1]);
                dp[i][j] = max(left, right);
            }
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ++g, dp[0][n-1]);
    }
    return 0;
}