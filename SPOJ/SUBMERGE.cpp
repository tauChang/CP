#include <iostream>
#include <vector>
using namespace std;
#define MAXN 10009

int timer;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN];
bool cut[MAXN];

void dfs(int u, int p){
    tin[u] = low[u] = timer++;
    int subtree = 0;
    for(auto& v:adj[u]){
        if(v == p) continue;
        
        if(tin[v] != -1) low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] && p != -1) cut[u] = 1;
            subtree++;
        }
    }
    if(p == -1 && subtree > 1) cut[u] = 1;
}

int main(){
    int n, m;
    while(1){
        scanf("%d %d", &n, &m);
        if(!n && !m) break;
        for(int i = 1; i <= n; ++i) {
            adj[i].clear();
            cut[i] = 0;
            tin[i] = low[i] = -1;
        }
        timer = 0;
        
        for(int i = 0, u, v; i < m; ++i){
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(tin[i] == -1) dfs(i, -1);
            // printf("%d %d %d %d\n", i, tin[i], low[i], cut[i]);
            cnt += cut[i];
        }
        printf("%d\n", cnt);
    }  
    return 0;
}