#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int D[N][N], a[N][N];

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        D[x1][y1]++;
        D[x2+1][y2+1]++;
        D[x1][y2+1]--;
        D[x2+1][y1]--;
    }

    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= m; y++) {
            a[x][y] = a[x][y-1] + a[x-1][y] - a[x-1][y-1] + D[x][y];
        }
    }

    return 0;
}
