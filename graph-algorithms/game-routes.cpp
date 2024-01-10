#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;


vector<vector<int>> adj(1e5+1);
vector<bool> visited(1e5+1, false);
int MOD = 1e9+7;


void solve() {
    int n, m; cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    // Topological Sort
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    // lengths[u] = number of paths from 1 to u
    vector<int> paths(n + 1, 0);
    paths[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            paths[v] += paths[u];
            paths[v] %= MOD;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << paths[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}