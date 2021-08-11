#include <iostream>
#include <cstring>
using namespace std;

char s[6109];
int dp[6109][6109];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        int n = strlen(s);
        for(int l = 2; l <= n; ++l){
            for(int i = 0, j; i+l-1 < n; ++i){
                j = i+l-1;
                dp[i][j] = s[i]==s[j] ? dp[i+1][j-1] : 1+min(dp[i+1][j], dp[i][j-1]);
            }
        }
        printf("%d\n", dp[0][n-1]);
    }
}