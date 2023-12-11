#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;
 

struct Edge {
    int a, b;
    ll c;
};

// vis[i] = true if node i is reachable from 1, visR[i] = true if node i can reach n
bool vis[2501], visR[2501]; 
// G[i] = nodes reachable from i, GR[i] = nodes that can reach i
vector<int> G[2501], GR[2501];

// dfs and dfsR are used to fill vis and visR
void dfs(int u) {
    vis[u] = true;
    for(int v : G[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}
void dfsR(int u) {
    visR[u] = true;
    for(int v : GR[u]) {
        if (!visR[v]) {
            dfsR(v);
        }
    }
}


void solve() {
    // This problem is solved using Bellman-Ford algorithm
    // Since we want to find the maximum distance, we make the distance negative
    // Then the shortest path to n will be the longest path to n
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        Edge e; cin >> e.a >> e.b >> e.c;
        e.c *= -1;
        edges.push_back(e);
        G[e.a].push_back(e.b);
        GR[e.b].push_back(e.a);
    }
    dfs(1);
    dfsR(n);

    vector<ll> dists(n+1, 1e17);
    bool improved = true; // improved = true if dists is improved in the last iteration
    dists[1] = 0;
    // Bellman-Ford algorithm
    for (int i = 0; i < n && improved; i++) {
        improved = false;
        for (Edge e : edges) {
            if (dists[e.a] != 1e17 && dists[e.b] > dists[e.a] + e.c) {
                dists[e.b] = dists[e.a] + e.c;
                improved = true;
                // If dist to e.b is improved in the last iteration
                // and e.b is reachable from 1 and can reach n
                // then there is a negative cycle
                if (i == n-1 && vis[e.b] && visR[e.b]) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    cout << -dists[n] << '\n';
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}