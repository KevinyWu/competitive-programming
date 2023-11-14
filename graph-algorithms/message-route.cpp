#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    vector<int> distance(n + 1, INT_MAX); // Keep track of minimum distance to each node
    vector<int> parents(n + 1, -1); // Keep track of the parent of each node in min path
    distance[1] = 0; // Distance to root is 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        // Get the closest unprocessed node
        int u = pq.top().second; pq.pop();
        if (u == n) {
            break;
        }
        // Update the distance to each neighbor of u if new distance is smaller
        for (int x : adj[u]) {
            if (distance[x] > distance[u] + 1) {
                distance[x] = distance[u] + 1;
                parents[x] = u;
                pq.push({distance[x], x});
            }
        }
    }
    if (distance[n] == INT_MAX) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    // Print the path
    vector<int> path = {n};
    int cur = n;
    while (parents[cur] != -1) {
        path.push_back(parents[cur]);
        cur = parents[cur];
    }
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}