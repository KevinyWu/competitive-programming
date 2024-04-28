#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define ll long long
using namespace std;


vector<ll> dijkstra(vector<vector<pair<ll, ll>>> adj, int n, int s, int k) {
    vector<vector<ll>> distance(n+1, vector<ll>(k, LLONG_MAX));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ll a = pq.top().second, d = pq.top().first;
        pq.pop();
        // Continue if the distance is already more than the kth best distance
        if (distance[a][k-1] < d) { 
            continue;
        }
        for (auto u : adj[a]) {
            ll b = u.first, w = u.second;
            if (d + w < distance[b][k-1]) {
                distance[b][k-1] = d + w;
                pq.push({distance[b][k-1], b});
                sort(distance[b].begin(), distance[b].end());
            }
        }
    }
    return distance[n];
}
 
 
void solve() {
    // We run Dijkstra's algorithm k times and store the k best distances in a vector
    // Modification of the standard algorithm where we only store the best distance
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> distance = dijkstra(adj, n, 1, k);
    for (auto i : distance) {
        cout << i << " ";
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}