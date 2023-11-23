#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
 
 
void solve() {
    // This problem is solved using Dijkstra's algorithm
    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> distance(n+1, LONG_MAX);
    vector<bool> visited(n+1, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    distance[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll a = pq.top().second; pq.pop();
        if (visited[a]) {
            continue;
        }
        visited[a] = true;
        for (auto u : adj[a]) {
            ll b = u.first, w = u.second;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                pq.push({distance[b], b});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << distance[i] << ' ';
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}