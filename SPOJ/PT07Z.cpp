#include <iostream>
#include <vector>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

vector<vector<int>> adj(10002);
vector<int> visited(10002, 0);
int lmax=0, gmax=0, gid;

void dfs(int u){
    visited[u] = 1;
    for(auto& v:adj[u]){
        if(!visited[v]) {
            if(++lmax > gmax) {
                gmax = lmax;
                gid = v;
            }
            dfs(v);
            --lmax;
        }
    }
}


int main(){
    AC
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    fill(visited.begin(), visited.begin()+n, 0);
    lmax = gmax = 0;
    dfs(gid);
    cout << gmax << endl;
}