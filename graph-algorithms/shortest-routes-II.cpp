#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
 
void solve() {
    // This problem is solved using Ford-Warshall algorithm
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> dists(n+1, vector<ll>(n+1, 1e18));
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        dists[a][a] = 0;
        dists[b][b] = 0;
        // Paths are bidirectional
        dists[a][b] = min(dists[a][b], c);
        dists[b][a] = min(dists[b][a], c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++)
                dists[j][k] = min(dists[j][k], dists[j][i] + dists[i][k]);
        }
    }
    while (q--) {
        int a, b; cin >> a >> b;
        if (dists[a][b] == 1e18) {
            cout << -1 << '\n';
        }
        else {
            cout << dists[a][b] << '\n';
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}