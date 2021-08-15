#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 53

char A[MAXN][MAXN];
int len[MAXN][MAXN];

int dfs(int i, int j){
    if(len[i][j] != -1) return len[i][j];

    len[i][j] = 1;
    for(int di = -1; di <= 1; ++di){
        for(int dj = -1; dj <= 1; ++dj){
            int ii = i+di, jj = j+dj;
            if(A[i][j]+1 == A[ii][jj]) len[i][j] = max(len[i][j], dfs(ii, jj)+1);
        }
    }
    return len[i][j];
}

int main(){
    int m, n, t = 1;
    while(1){
        memset(A, 'x', sizeof(A));
        memset(len, -1, sizeof(len));

        scanf("%d %d", &m, &n);
        if(!m) break;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) scanf(" %c", &A[i][j]);
        }

        int ans = 0;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j) {
                if(A[i][j] == 'A') ans = max(ans, dfs(i, j));
            }
        }
        
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}