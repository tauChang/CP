/*
 tag: graph, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
#define MAXN 505
int adj[MAXN][MAXN];

int main(){
    int n, m;
    while(1){
        scanf("%d %d", &n, &m);
        if(!n && !m) break;
        for(int u = 1; u <= n; ++u) {
            for(int v = 1; v <= n; ++v) adj[u][v] = MAXN;
        }
        for(int i = 0, u, v; i < m; ++i){
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
        }
        for(int k = 1; k <= n; ++k){
            for(int u = 1; u <= n; ++u){
                for(int v = 1; v <= n; ++v){
                    adj[u][v] = min(adj[u][v], adj[u][k]+adj[k][v]);
                }
            }
        }
        int ans = MAXN;
        for(int u = 1; u <= n; ++u) ans = min(ans, adj[u][u]);
        printf("%d\n", ans==MAXN?0:ans);
    }
    return 0;
}