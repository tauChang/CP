/*
 tag: dp, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
#define MAXN 52
#define MAXT 10005
int w[MAXN], v[MAXN], c[MAXN];
int dp[MAXT];

int main(){
    int n, t;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d %d %d", &w[i], &v[i], &c[i]);
    scanf("%d", &t);
    for(int i = 0; i < n; ++i){
        int num = min(c[i], t/w[i]);
        for(int j = 1; num; j <<= 1) {
            if(num < j) j = num;
            num -= j; 
            for(int k = t; k - w[i]*j >= 0; --k){
                dp[k] = max(dp[k], dp[k-w[i]*j]+v[i]*j);
            }
        }
    }
    printf("%d", dp[t]);
}