#include <iostream>
#include <vector>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> adj(10003);
vector<bool> visited(10003, 0);
int cnt;
bool cycle = false;

void dfs(int u, int par){
    ++cnt;
    visited[u] = 1;
    for(auto& v:adj[u]){
        if(visited[v]) cycle = v!=par;
        else dfs(v, u);
        if(cycle) return;
    }
}

int main(){
    AC
    int n, m, u, v;
    cin >> n >> m;
    if(m != n-1) {
        cout << "NO";
        return 0;
    }
    while(m--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    if(cnt == n && !cycle) cout << "YES";
    else cout << "NO";

    return 0;
}