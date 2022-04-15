/*
 tag: dp, easy
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
#define MAXN 3005
int arr[MAXN][MAXN], dp[2][MAXN];

int main(){
    int m, n, ans = -10;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j) scanf("%d", &arr[i][j]);
    }
    for(int i = m-1; i >= 0; --i){
        for(int j = n-1; j >= 0; --j){
            dp[0][j] = arr[i][j] + max(0, max(dp[1][j], dp[0][j+1]));
            ans = max(ans, dp[0][j]);
        }
        swap(dp[0], dp[1]);
        memset(dp[0], 0, sizeof(dp[0]));
    }
    printf("%d", ans);
}