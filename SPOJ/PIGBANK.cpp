#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAXW 10004
#define MAXN 503
typedef long long ll;

ll dp[MAXW];
int v[MAXN], w[MAXN];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int e, f, n, ans = INT_MAX;
        scanf("%d %d", &e, &f);
        f -= e;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d %d", &v[i], &w[i]);

        for(int i = 1; i <= f; ++i){
            dp[i] = INT_MAX;
            for(int j = 0; j < n; ++j) {
                if(i >= w[j]) dp[i] = min(dp[i], dp[i-w[j]]+v[j]);
            }
        }

        if(dp[f] >= INT_MAX) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %lld.\n", dp[f]);
    }
    return 0;
}