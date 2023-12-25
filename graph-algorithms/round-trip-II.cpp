#include <iostream>
#include <vector>
#define ll long long
using namespace std;


vector<vector<int>> adj(100001);
vector<int> visited(100001, 0);
vector<int> parent(100001, -1);
int cycle_start, cycle_end;


// If visited = 0, node is unvisited
// If visited = 1, node is visited in current DFS
// If visited = 2, full DFS starting at that node is complete
void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 0) { 
            parent[v] = u;
            dfs(v);
            if (cycle_start != -1) return;
        }
        // If v is already visited, a cycle is found
        else if (visited[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return;
        }
    }
    visited[u] = 2;
}


void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    cycle_start = -1;
    // Run DFS from every unvisited node
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0 && cycle_start == -1) {
            dfs(i);
        }  
    }
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    // It is important to start at cycle_end and not cycle_start
    // Recall that cycle_start may not have a parent
    for (int u = cycle_end; u != cycle_start; u = parent[u]) {
        cycle.push_back(u);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (int u : cycle) {
        cout << u << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}