#include <iostream>
#include <vector>
#define ll long long
using namespace std;


vector<vector<int>> adj(100001);
vector<bool> visited(100001, false);
vector<int> parent(100001, -1);
int cycle_start, cycle_end;


bool dfs(int u, int par) {
    visited[u] = true;
    for (int v : adj[u]) {
        // If u is parent of v, continue, since a cycle must have at least 3 nodes
        if (v == par) { 
            continue;
        }
        // If u is already visited, this means it was visited from another node
        // So, a cycle is found starting at v and ending at u
        if (visited[v]) { 
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        // Else, mark u as parent of v and continue DFS
        parent[v] = u;
        if (dfs(v, parent[v])) {
            return true;
        }
    }
    return false;
}


void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cycle_start = -1;
    // Run DFS from every unvisited node
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, parent[i])) {
            break;
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