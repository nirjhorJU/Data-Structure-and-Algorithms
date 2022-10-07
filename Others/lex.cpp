#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

vector<pair<int,int>> G[N];
bool vis[N];
int par[N];

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    int source, target;
    cin >> source >> target;

    vector<pair<int,int>> cur_nodes = {{1, source}};
    vis[source] = true;
    par[source] = -1;
    while(cur_nodes.size() > 0) {
        vector<tuple<int,int,int,int>> nxt_nodes;
        for(int i = 0; i < cur_nodes.size(); i++) {
            int u = cur_nodes[i].second;
            for(int j = 0; j < G[u].size(); j++) {
                nxt_nodes.push_back(make_tuple(cur_nodes[i].first, G[u][j].second, G[u][j].first, u));
            }
        }
        sort(nxt_nodes.begin(), nxt_nodes.end());
        vector<tuple<int,int,int>> visited;
        for(int i = 0; i < nxt_nodes.size(); i++) {
            int v = get<2>(nxt_nodes[i]);
            if(vis[v]) continue;
            vis[v] = true;
            par[v] = get<3>(nxt_nodes[i]);
            visited.push_back(make_tuple(get<0>(nxt_nodes[i]), get<1>(nxt_nodes[i]), v));
        }
        int rnk = 0;
        cur_nodes.clear();
        for(int i = 0; i < visited.size(); i++) {
            if(i == 0 or get<0>(visited[i-1]) != get<0>(visited[i]) or get<1>(visited[i-1]) != get<1>(visited[i])) ++rnk;
            cur_nodes.push_back({rnk, get<2>(visited[i])});
        }
    }

    vector<int> path;
    int u = target;
    while(u != -1) {
        path.push_back(u);
        u = par[u];
    }
    reverse(path.begin(), path.end());
    for(int u : path) cout << u << " ";
    cout << endl;

    return 0;
}
