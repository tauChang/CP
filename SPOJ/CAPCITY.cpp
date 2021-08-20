#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
vector<int> adj[MAXN];
int stk[MAXN], top;
int tin[MAXN], low[MAXN], t = 1;
int candCount;
bool onStk[MAXN], outDeg[MAXN], isCand[MAXN];

void dfs(int u){
    tin[u] = low[u] = t++;
    stk[++top] = u;
    onStk[u] = 1;
    for(int& v:adj[u]) {
        if(!low[v]) dfs(v);
        
        if(onStk[v]) low[u] = min(low[u], low[v]);
        else outDeg[u] = 1;
    }
    if(low[u] == tin[u]) {
        bool isSink = 1;
        vector<int> scc;
        while(top) {
            int v = stk[top];
            scc.push_back(v);
            isSink &= !outDeg[v];
            onStk[v] = 0;
            if(stk[top--] == u) break;
        }
        if(isSink) {
            candCount += scc.size();
            for(int& v:scc) isCand[v] = 1;
        }
    }
}

int main(){
    int n, m;
    scanf(" %d %d", &n, &m);
    for(int i = 0, u, v; i < m; ++i) {
        scanf(" %d %d", &u, &v);
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i) if(!low[i]) dfs(i);

    printf("%d\n", candCount);
    for(int i = 1; i <= n; ++i) if(isCand[i]) printf("%d ", i);

    return 0;
}