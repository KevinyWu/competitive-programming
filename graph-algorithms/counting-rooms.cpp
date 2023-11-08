#include <iostream>
#include <vector>
#define ll long long
using namespace std;


bool visited[1000][1000]; // Set to false by default
int n, m;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


void dfs(int x, int y) {
    visited[x][y] = true;
    for (auto move : moves) {
        int dx = x + move.first, dy = y + move.second;
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy]) {
            dfs(dx, dy);
        }
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#') {
                // Mark walls as visited
                visited[i][j] = true;
            }
        }
    }
    int ans = 0;
    // Loop through all vertices
    // If a vertex is unvisited, that means it is part of a new component
    // DFS from that vertex to visit that component entirely
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                ans++;
            }
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