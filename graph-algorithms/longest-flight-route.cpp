#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;


vector<vector<int>> adj(1e5+1);
vector<bool> visited(1e5+1, false);


void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}


void solve() {
    int n, m; cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    // Check if a path from 1 to n exists
    dfs(1);
    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    // Topological Sort
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    // lengths[v] = length of longest path from 1 to v
    // parents[v] = parent of v in the longest path from 1 to v
    vector<int> lengths(n + 1, 0), parents(n + 1, 0);
    lengths[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            // Update lengths[v] and parents[v] when a longer path is found
            // Only update lengths[v] if u has been visited before, i.e. lengths[u] != 0
            // This is so we avoid paths that don't start from 1
            if (lengths[u] != 0 && lengths[v] < lengths[u] + 1) {
                lengths[v] = lengths[u] + 1;
                parents[v] = u;
            }
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << lengths[n] << '\n';
    // Reconstruct the path
    vector<int> ans;
    int u = n;
    while (u != 1) {
        ans.push_back(u);
        u = parents[u];
    }
    ans.push_back(1);
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}