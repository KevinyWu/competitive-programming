#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define ll long long
using namespace std;


void solve() {
    // This problem is solved using Dijkstra's algorithm
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<int> distance(n+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int a = pq.top().second; pq.pop();
        for (auto b: adj[a]) {
            if (distance[a] + b.second < distance[b.first]) {
                distance[b.first] = distance[a] + b.second;
                pq.push({distance[b.first], b.first});
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