#include <iostream>
#include <vector>
#define ll long long
using namespace std;


struct Edge {
    int a, b;
    ll c;
};


void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        Edge e; cin >> e.a >> e.b >> e.c;
        edges.push_back(e);
    }
    vector<ll> dists(n+1, 1e18);
    dists[1] = 0;
    vector<int> parents(n+1, -1);
    int start = -1;
    // Bellman-Ford algorithm
    for (int i = 0; i < n && start; i++) {
        start = 0;
        for (Edge e : edges) {
            if (dists[e.b] > dists[e.a] + e.c) {
                dists[e.b] = dists[e.a] + e.c;
                parents[e.b] = e.a;
                start = e.b;
            }
        }
    }
    // If dists is improved in the last iteration, there is a negative cycle
    if (!start) {
        cout << "NO\n";
        return;
    }
    // Print the negative cycle
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        start = parents[start];
    }
    vector<int> cycle;
    for (int cur = start;; cur = parents[cur]) {
        cycle.push_back(cur);
        if (cur == start && cycle.size() > 1) {
            break;
        }
    }
    reverse(cycle.begin(), cycle.end());
    for (int i : cycle) {
        cout << i << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}