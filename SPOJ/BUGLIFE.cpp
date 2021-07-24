#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> adj;
vector<int> stat;
bool odd;

void dfs(int u, int val){
    stat[u]=val;
    for(int& v:adj[u]){
        if(stat[v] == -1) dfs(v, 1-val);
        else odd = stat[v]==stat[u];
        if(odd) return;
    }
}

int main(){
    AC
    int c;
    cin >> c;
    for(int i = 1; i <= c; ++i){
        int n, m;
        cin >> n >> m;
        adj.clear(); adj.resize(n+1);
        stat.clear(); stat.resize(n+1, -1);
        odd = false;
        while(m--){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int u = 1; u <= n && !odd; ++u){
            if(stat[u] == -1) dfs(u, 0);
        }
        printf("Scenario #%d:\n", i);
        if(odd) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
    }

    return 0;
}