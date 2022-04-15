/*
 tag: vertex cover, dp, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
#define F first
#define S second
vector<vector<int>> adj;
int memo[10005][2];
bool visited[10005];

void dfs(int u){
    visited[u] = 1;
    memo[u][1] = 1;
    for(auto& v:adj[u]){
        if (visited[v]) continue;
        dfs(v);
        memo[u][0] += memo[v][1];
        memo[u][1] += min(memo[v][0], memo[v][1]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    adj.resize(n+1);
    for(int i = 0, u, v; i < n-1; ++i){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    printf("%d", min(memo[1][0], memo[1][1]));
    return 0;
}