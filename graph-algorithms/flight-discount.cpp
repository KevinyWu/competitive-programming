#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#define ll long long
using namespace std;


vector<ll> dijkstra(vector<vector<pair<ll, ll>>> adj, int n, int s) {
    vector<ll> distance(n+1, LONG_MAX);
    vector<bool> visited(n+1, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    distance[s] = 0;
    pq.push({0, s});
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
    return distance;
}
 
 
void solve() {
    // We run Dijkstra's algorithm twice, once from 1 to n and once from n to 1
    // We then iterate through all edges and find the minimum of the following:
    // min_(A->B) distance[A] + distanceR[B] + cost(A->B)/2
    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1), adjR(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adjR[b].push_back({a, c});
    }
    vector<ll> distance = dijkstra(adj, n, 1);
    vector<ll> distanceR = dijkstra(adjR, n, n);
    ll ans = LONG_MAX;
    for (int i = 1; i <= n; i++) {
        for (auto u : adj[i]) {
            ll a = i, b = u.first, w = u.second;
            if (distance[a] == LONG_MAX || distanceR[b] == LONG_MAX) {
                continue;
            }
            ans = min(ans, distance[a] + distanceR[b] + w/2);
        }
    }
    cout << ans << '\n';
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}