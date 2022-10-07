#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

vector<int> g[N];
bool vis[N];
int depth[N], low[N];

void dfs(int u, int p, int d) {
    vis[u] = true;
    low[u] = depth[u] = d;
    for(int v : g[u]) {
        if(v == p) continue;
        if(vis[u] == 0) {
            dfs(v, u, d+1);
            low[u] = min(low[u], low[v]);
        }
        else {
            if(depth[v] < depth[u]) {
                low[u] = min(low[u], depth[v]);
            }
        }
    }
    if(low[u] < depth[u]) {
        /// p - u edge is a bridge
    }
}


int main() {

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1,0);

    return 0;
}


