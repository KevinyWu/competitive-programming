#include <iostream>
#include <vector>
#define ll long long
using namespace std;


int n, m;
vector<vector<int>> adj(100001);
vector<bool> visited(100001, false);
vector<int> roads;


void dfs(int a) {
    visited[a] = true;
    for (int b : adj[a]) {
        if (!visited[b]) {
            dfs(b);
        }
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // Make a bridge each time a disconnected graph is seen
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            roads.push_back(i);
            dfs(i);
        }
    }
    cout << roads.size() - 1 << '\n';
    for (int i = 0; i < roads.size() - 1; i++) {
        cout << roads[i] << ' ' << roads[i + 1] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}