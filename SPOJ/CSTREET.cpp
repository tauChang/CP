#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

class Edge{
    public:
    int v;
    int w;
};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int p, n, m, f = 0;
        scanf("%d %d %d", &p, &n, &m);
        vector<vector<Edge>> adj(n+1);
        while(m--){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool> done(n+1, false);
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        Q.push({0, 1});
        while(Q.size()){
            pii p = Q.top(); Q.pop();
            int u = p.second, w = p.first;
            if(done[u]) continue;
            done[u] = true;
            f += w;
            for(auto& e:adj[u]) if(!done[e.v]) Q.push({e.w, e.v});
        }
        printf("%d\n", f*p);
    }
    return 0;
}