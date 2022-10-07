#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+100, ALPHA = 26;

int to[N][ALPHA], nxt[N][ALPHA];
int dph[N], sl[N], par[N], pl[N];
vector<int> tr[N];
int tot = 1;

int add_string(string &s) {
    int u = 1;
    for(int i = 0; i < s.size(); i++) {
        int c = s[i]-'a';
        if(!to[u][c]) to[u][c] = ++tot, par[tot] = u, dph[tot] = dph[u]+1, pl[tot] = c;
        u = to[u][c];
    }
    return u;
}

void push_links() {
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if(dph[u] <= 1) sl[u] = 1;
        else {
            int v = sl[par[u]], l = pl[u];
            while(v > 1 && !to[v][l]) v = sl[v];
            if(to[v][l]) v = to[v][l];
            sl[u] = v;
        }
        if(u != 1) tr[sl[u]].push_back(u);
        for(int i = 0; i < ALPHA; i++) if(to[u][i]) q.push(to[u][i]);
    }
}

int jump(int u, int c) {
    if(nxt[u][c]) return nxt[u][c];
    int v = u;
    while(v > 1 && !to[v][c]) v = sl[v];
    if(to[v][c]) v = to[v][c];
    return nxt[u][c] = v;
}


int main() {

}
