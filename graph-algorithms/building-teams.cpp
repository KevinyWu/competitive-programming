#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> group(n + 1, 0);
    queue<int> q;
    // Loop through all pupils
    // If a pupil is unvisited, that means we can assign it team 1
    // BFS from that pupil to assign all its friends to the oppositie team
    for (int i = 1; i <= n; i++) {
        if (group[i] == 0) {
            q.push(i);
            group[i] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (group[v] == 0) {
                        group[v] = 3 - group[u];
                        q.push(v);
                    }
                    // If a friend of that pupil is already in the same team, break
                    else if (group[v] == group[u]) {
                        cout << "IMPOSSIBLE";
                        return;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << group[i] << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}